// MemoryOrderRelaxed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <assert.h>

std::atomic<bool> x{ false }, y{ false };
std::atomic<int> z{ 0 };

/*
void write_x_then_y()
{
    x.store(true, std::memory_order_relaxed);
    std::cout << "x stored" << std::endl;

    y.store(true, std::memory_order_release);
    std::cout << "y stored" << std::endl;

}

void read_y_then_x()
{
    int count = 0;
    while (!y.load(std::memory_order_acquire)) {
        std::cout << "count : " << ++count << std::endl;

        std::cout << "y loaded" << std::endl;
    }


    if (x.load(std::memory_order_relaxed)) {
        std::cout << "x loaded" << std::endl;
        z++;
    }
}*/
void write_x()
{
    x.store(true, std::memory_order_release);
    std::cout << "x stored" << std::endl;
}

void write_y()
{
    y.store(true, std::memory_order_release);
    std::cout << "y stored" << std::endl;

}

void read_x_then_y()
{
    while (!x.load(std::memory_order_acquire)) 
        std::cout << "read_x_then_y : x load" << std::endl;


    if (y.load(std::memory_order_acquire)) {
        std::cout << "read_x_then_y : y load" << std::endl;
        z++;
    }
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_acquire))
        std::cout << "read_y_then_x : y load" << std::endl;


    if (x.load(std::memory_order_acquire)) {
        std::cout << "read_y_then_x : x load" << std::endl;
        z++;
    }
}


int main()
{
    /*std::thread t1(write_x_then_y);
    std::thread t2(read_y_then_x);

    t1.join();
    t2.join();*/

    std::thread t1(write_x);
    std::thread t2(write_y);
    std::thread t4(read_y_then_x);
    std::thread t3(read_x_then_y);


    t1.join();
    t2.join();
    t3.join();
    t4.join();

    assert(z != 0);
    std::cout << z << std::endl;
}

