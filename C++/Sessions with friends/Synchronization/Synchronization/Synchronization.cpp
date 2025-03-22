// Synchronization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

//################# Modern c++ ######################
//mutex
//lock
//unlock
//try_lock
//unique_lock
//lock_guard
//
//conditional_variable
//wait
//wait_for
//wait_until
//notify_once
//notify_all
//
//recursive mutex
//
//semaphore
//binary semaphore
//Counting Semaphore
// 
//Future
//Promise
//asyn
//Package_task
//Latches and Barriers

//Atomic variable
//call_once
//once_flag


//################ OS Sync techniques #################
//critical section
//Mutex
//Semaphore - Binary and counting 
//Event
//Locking types
//Contidion variable


//deadlock
//race condition

std::mutex m1;
std::mutex m2;

void print()
{

    //for (int i = 0; i < 100; i++) 
    {
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Acquring mutex by thread 1" << std::endl;
        std::lock_guard<std::mutex> lg1(m1);
        //std::lock_guard<std::mutex> lg2(m2);

        std::cout << "thread 1 :" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "released mutex by thread 1" << std::endl;
}

void print1()
{
    
    //for (int i = 0; i < 100; i++)
    {

       // std::lock_guard<std::mutex> lg2(m2);
        std::lock_guard<std::mutex> lg1(m1);

        std::cout << "thread 2 :" << std::endl;
        throw 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
    std::cout << "released mutex by thread 1" << std::endl;
}


int main()
{
    std::atomic<int> atomic_int;


    //std::thread t1(print);
    std::thread t2(print1);

    

    //t1.join();
    t2.join();
}
