#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
    int count;
    mutex mtx;
    condition_variable cv1, cv2, cv3;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        //unique_lock<mutex> lck(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
       // cv1.wait(lck);
        printFirst();
        cv2.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        // printSecond() outputs "second". Do not change or remove this line.
        cv2.wait(lck);
        printSecond();
        cv3.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        // printThird() outputs "third". Do not change or remove this line.
        cv3.wait(lck);
        printThird();
    }
};

void test_1114()
{
    Foo f;
    std::jthread t1(&Foo::first, &f, []() { std::cout << "first\n"; });
    std::jthread t2(&Foo::second, &f, []() { std::cout << "second\n"; });
    std::jthread t3(&Foo::third, &f, []() { std::cout << "third\n"; });
   
}