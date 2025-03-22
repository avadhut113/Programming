// ReleaseSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> count;
std::vector<int> Q;


void write_queue()
{
    for (int i = 0; i < 20; i++)
        Q.emplace_back(i);

    count.store(20, std::memory_order_release);
}

void read_queue()
{
    
    while (true) {
        int index = 0;
        if (!(index = count.fetch_sub(1,std::memory_order_acquire) < 0)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        std::cout << std::this_thread::get_id() << " : " << Q[index] << std::endl;
    }
}

int main()
{
    std::thread t1(write_queue);
    std::thread t2(read_queue);
    std::thread t3(read_queue);

    t1.join();
    t2.join();
    t3.join();
}

