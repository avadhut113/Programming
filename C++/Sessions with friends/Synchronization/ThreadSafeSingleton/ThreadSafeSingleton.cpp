// ThreadSafeSingleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <atomic>
#include <memory>
#include <chrono>
#include <future>

class Singleton {
public:
    static Singleton& get_instance() {
        static std::atomic<Singleton*> instance{ nullptr };
        Singleton* expected = nullptr;
        if (!instance.compare_exchange_strong(expected, new Singleton)) {
            delete expected;
        }
        return *instance;
    }

private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

std::chrono::duration<double> getTime() 
{

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= 1000000; ++i) {
        Singleton::get_instance();
    }
    return std::chrono::system_clock::now() - begin;

};


int main() {

    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);

    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::cout << total.count() << std::endl;

}


