// Happen_before_relationship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

std::atomic<bool> flag{false};
std::vector<int> data;

void reader()
{
    int i = 0;
    while (!flag) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        i++;
        std::cout << i << std::endl;
    }

    std::cout << data[0] << std::endl;
}

void writer()
{
    data.push_back(10);
    flag = true;
}

int main()
{
    std::thread t2(reader);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::thread t1(writer);

    t1.join();
    t2.join();

}

