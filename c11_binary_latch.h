#ifndef HOUSTON_C11_BINARY_LATCH_H
#define HOUSTON_C11_BINARY_LATCH_H

#include <condition_variable>
#include <mutex>

namespace houston {
    /**
     * Represents a single-use latch which can have multiple
     * waiting threads which are released by the release()
     * method. This is implemented for C11.
     */
    class c11_binary_latch {
    private:
        std::mutex mutex;
        std::condition_variable cond;
        bool released{false};
    public:
        /**
         * Blocks until a thread calls release(), unless the
         * release() method has already been called.
         */
        void wait();

        /**
         * Releases all threads blocked on the call to wait().
         */
        void release();
    };
}

#endif // HOUSTON_C11_BINARY_LATCH_H
