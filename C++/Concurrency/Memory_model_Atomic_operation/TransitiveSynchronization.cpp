// TransitiveSynchronization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <assert.h>

std::atomic<int> arr[5];
std::atomic<bool> sync1{ false }, sync2{ false };

void thread_func1()
{
    arr[0].store(1, std::memory_order_relaxed);
    arr[1].store(2, std::memory_order_relaxed);
    arr[2].store(3, std::memory_order_relaxed);
    arr[3].store(4, std::memory_order_relaxed);
    arr[4].store(5, std::memory_order_relaxed);
    sync1.store(true, std::memory_order_release);
}

void thread_func2()
{
    while (!sync1.load(std::memory_order_acquire));
    sync2.store(true, std::memory_order_release);
}

void thread_func3()
{
    while (!sync2.load(std::memory_order_acquire));
    assert(arr[0].load(std::memory_order_relaxed) == 1);
    assert(arr[1].load(std::memory_order_relaxed) == 2);
    assert(arr[2].load(std::memory_order_relaxed) == 3);
    assert(arr[3].load(std::memory_order_relaxed) == 4);
    assert(arr[4].load(std::memory_order_relaxed) == 5);
}

int main()
{
    std::thread t1(thread_func1);
    std::thread t2(thread_func2);
    std::thread t3(thread_func3);


    t1.join();
    t2.join();
    t3.join();
}
