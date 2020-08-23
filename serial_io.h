#ifndef HOUSTON_SERIAL_IO_H
#define HOUSTON_SERIAL_IO_H

#include "c11_binary_latch.h"
#include "mutex_fifo_queue.h"
#include "body_model.h"

namespace houston {
    /**
     * Represents a serial IO thread.
     */
    class serial_io {
    private:
        const std::string &port;
        c11_binary_latch ready_latch;
        mutex_fifo_queue<std::string> cmd_queue;
        body_model model;
        std::thread thread;

        void run();

    public:
        /**
         * Constructs a new serial IO thread and runs it.
         *
         * @param port the serial port which to bind
         */
        explicit serial_io(const std::string &port);

        /**
         * Obtains the ready latch which is released when
         * it is determined that the serial endpoint is
         * ready to receive commands.
         *
         * @return the ready latch
         */
        c11_binary_latch &get_ready_latch();

        /**
         * Obtains the queue of commands scanned by this
         * thread to be sent when the serial target is
         * ready.
         *
         * @return the queue of commands to be sent
         */
        mutex_fifo_queue<std::string> &get_cmd_queue();

        /**
         * Waits for this thread to complete execution.
         */
        void join();
    };
}

#endif // HOUSTON_SERIAL_IO_H
