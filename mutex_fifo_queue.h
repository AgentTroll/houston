#ifndef HOUSTON_MUTEX_FIFO_QUEUE_H
#define HOUSTON_MUTEX_FIFO_QUEUE_H

#include <mutex>
#include <deque>

namespace houston {
    /**
     * A first-in, first-out (FIFO) queue implemented with
     * a mutex to ensure thread-safety.
     *
     * @tparam T the type of elements held in the queue
     */
    template<typename T>
    class mutex_fifo_queue {
    private:
        std::mutex mutex;
        std::deque<T> delegate;
    public:
        /**
         * Determines if the queue is empty.
         *
         * @return true if empty
         */
        bool empty() {
            std::lock_guard<std::mutex> lock{mutex};
            return delegate.empty();
        }

        /**
         * Adds an item to the head of the queue.
         *
         * @param item the item to add
         */
        void push(const T &item) {
            std::lock_guard<std::mutex> lock{mutex};
            delegate.push_front(item);
        }

        /**
         * Reads the item at the tail of the queue.
         *
         * @return the item at the tail of the queue
         */
        T &back() {
            std::lock_guard<std::mutex> lock{mutex};
            return delegate.back();
        }

        /**
         * Pops the item at the end of the queue and
         * removes it.
         */
        void pop_back() {
            std::lock_guard<std::mutex> lock{mutex};
            delegate.pop_back();
        }
    };
}

#endif // HOUSTON_MUTEX_FIFO_QUEUE_H
