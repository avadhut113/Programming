// SpinLockMutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>


class SpinLock_Mutex
{
    std::atomic_flag flag{ ATOMIC_FLAG_INIT };
public:
    void lock() {
        while (!flag.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

SpinLock_Mutex mutex;

void thread_func()
{
    std::lock_guard<SpinLock_Mutex>lg(mutex);
    std::cout << std::this_thread::get_id() << " Hello" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main()
{
    std::thread t1(thread_func);
    std::thread t2(thread_func);

    t1.join();
    t2.join();
}
