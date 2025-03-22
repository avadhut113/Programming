// MemoryOrder_Consume.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <memory>
#include <assert.h>

struct X {
    int i{ 0 };
    std::string str{ "" };
    ~X() { std::cout << __FUNCTION__ << std::endl; }
};

//static_assert failed: 'atomic<T> requires T to be trivially copyable, copy constructible, move constructible, copy assignable, and move assignable.'
//std::atomic<std::shared_ptr<X>> x_ptr{ nullptr };

std::atomic<X*> x_ptr{ nullptr };
std::atomic<int> a;

//Carries dependency to
void store_x()
{
    //std::shared_ptr<X> x(new X());
    X* x = new X();
    x->i = 10;
    x->str = "abc";

    a.store(20, std::memory_order_relaxed);
    //*x carries dependecy to z_ptr
    x_ptr.store(x, std::memory_order_release);
}

//Dependency order before 
void use_x()
{
    //std::shared_ptr<X> x(new X());
    X* x{ nullptr };
    while (!(x = x_ptr.load(std::memory_order_consume)));
    assert(x->i == 10);
    assert(x->str == "abc");
    assert(a.load(std::memory_order_relaxed) == 20);

}

int main()
{
    std::thread t1(store_x);
    std::thread t2(use_x);


    t1.join();
    t2.join();
}
