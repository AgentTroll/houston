#include <fstream>
#include <iostream>
#include <thread>
#include "mutex_fifo_queue.h"
#include "serial_io.h"

/**
 * Scans trajectory data from file and sends them to the
 * Arduino as TRAJECTORY commands to load the flight
 * profile.
 *
 * @param io_thread the handler thread for the Arduino
 */
static void scan_trajectory(houston::serial_io &io_thread) {
    std::ifstream trajectory{"./data/trajectory.csv"};
    if (!trajectory.good()) {
        std::cerr << "Failed to find ./data/trajectory.csv" << std::endl;
        trajectory.close();
        return;
    }

    std::string line;
    while (std::getline(trajectory, line)) {
        std::string cmd = "TRAJECTORY " + line;
        io_thread.get_cmd_queue().push(cmd);
    }

    trajectory.close();
}

/**
 * Scans the console for command input indefinitely to pass
 * commands to the IO thread.
 *
 * @param io_thread the handler thread for the Arduino
 */
static void scan_input(houston::serial_io &io_thread) {
    while (true) {
        std::cout << "$ ";

        std::string command;
        std::getline(std::cin, command);

        io_thread.get_cmd_queue().push(command);
        if (command == "QUIT") {
            return;
        }
    }
}

int main() {
    houston::serial_io io_thread{"/dev/ttyUSB0"};
    io_thread.get_ready_latch().wait();

    // scan_trajectory(io_thread);
    scan_input(io_thread);

    io_thread.join();
    return 0;
}
