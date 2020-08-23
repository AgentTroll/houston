#include "c11_binary_latch.h"

void houston::c11_binary_latch::wait() {
    std::unique_lock<std::mutex> lock{mutex};
    while (!released) {
        cond.wait(lock);
    }
}

void houston::c11_binary_latch::release() {
    {
        std::lock_guard<std::mutex> lock{mutex};
        released = true;
    }
    cond.notify_all();
}
