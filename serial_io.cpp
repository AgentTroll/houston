#include <thread>
#include <serial/serial.h>
#include <iostream>
#include "serial_io.h"

static const std::chrono::milliseconds SENSOR_UPDATE_DELAY{200};
static const std::chrono::milliseconds MIN_CMD_DELAY{50};

void houston::serial_io::run() {
    serial::Serial serial_port{port};
    std::cout << "Connected to " << serial_port.getPort() << std::endl;

    bool is_ready{false};
    std::string accum;

    auto last_cmd_time = std::chrono::high_resolution_clock::now();
    auto last_sensor_time = std::chrono::high_resolution_clock::now();

    while (true) {
        if (serial_port.available()) {
            const std::string &str = serial_port.read();
            accum += str;

            if (str == "\n") {
                unsigned long cmd_idx = accum.find(' ');
                std::string cmd = accum.substr(0, cmd_idx);

                if (cmd == "READY") {
                    is_ready = true;
                    ready_latch.release();
                } else if (cmd == "TELEMETRY") {
                    double vx_throttle;
                    double vy_throttle;
                    double vz_throttle;

                    unsigned long throttle_idx = accum.find(' ', cmd_idx + 1);
                    std::string throttle_args = accum.substr(throttle_idx);
                    std::istringstream iss{throttle_args};
                    iss >> vx_throttle;
                    iss >> vy_throttle;
                    iss >> vz_throttle;

                    model.set_velocity(vx_throttle, vy_throttle, vz_throttle);

                    std::cout << accum;
                } else if (cmd == "INFO") {
                    std::cout << accum;
                } else if (cmd == "ERROR:") {
                    std::cerr << accum;
                } else {
                    std::cerr << "Unknown command: " << accum;
                }

                accum.clear();
            }
        }

        auto last_sensor_elapsed = std::chrono::high_resolution_clock::now() - last_sensor_time;
        if (is_ready && last_sensor_elapsed >= SENSOR_UPDATE_DELAY) {
            model.update_motion((double) SENSOR_UPDATE_DELAY.count() / 1000);

            std::ostringstream oss;
            oss << "SENSOR " << model.get_x() << " " << model.get_y() << " " << model.get_z() << " "
                << model.get_vx() << " " << model.get_vy() << " " << model.get_vz();
            std::string cmd = oss.str();
            cmd_queue.push(cmd);

            last_sensor_time = std::chrono::high_resolution_clock::now();
        }

        if (is_ready && !cmd_queue.empty()) {
            auto last_cmd_elapsed = std::chrono::high_resolution_clock::now() - last_cmd_time;
            if (last_cmd_elapsed < MIN_CMD_DELAY) {
                continue;
            }

            std::string next_command = cmd_queue.back();
            if (next_command == "QUIT") {
                break;
            }

            next_command += " \n";
            serial_port.write(next_command);
            serial_port.flushOutput();

            cmd_queue.pop_back();
            last_cmd_time = std::chrono::high_resolution_clock::now();
        }
    }

    serial_port.close();
}

houston::serial_io::serial_io(const std::string &port) : port(port) {
    thread = std::thread{&houston::serial_io::run, this};
}

houston::c11_binary_latch &houston::serial_io::get_ready_latch() {
    return ready_latch;
}

houston::mutex_fifo_queue<std::string> &houston::serial_io::get_cmd_queue() {
    return cmd_queue;
}

void houston::serial_io::join() {
    thread.join();
}
