#pragma once
#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

//class ZeroEvenOdd {
//private:
//    int n;
//    mutex mtx;
//    condition_variable cv;
//    int next{ -1 }; //-1 for zero, 1 for odd, 0 for even
//    int count{ 1 };
//public:
//    ZeroEvenOdd(int n) : n(n) {
//    }
//
//    void zero(function<void(int)> printNumber) {
//        while (count <= n) {
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck, [this]() {return next == -1; });
//            if (count <= n) {
//                printNumber(0);
//            }
//            next = count % 2;
//            lck.unlock();
//            cv.notify_all();
//        }
//
//        return;
//    }
//
//    void even(function<void(int)> printNumber) {
//        while (count <= n) {
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck, [this]() {return next == 0; });
//            if (count <= n) {
//                printNumber(count);
//            }
//            count++;
//            next = -1;
//            lck.unlock();
//            cv.notify_all();
//        }
//        return;
//    }
//
//    void odd(function<void(int)> printNumber) {
//        while (count <= n) {
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck, [this]() {return next == 1; });
//            if (count <= n) {
//                printNumber(count);
//            }
//            count++;
//            next = -1;
//            lck.unlock();
//            cv.notify_all();
//        }
//        return;
//    }
//};


class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cvZero, cvEven, cvOdd;
    int next{ -1 }; //-1 for zero, 1 for odd, 0 for even
    int count{ 1 };
public:
    ZeroEvenOdd(int n) : n(n) {
    }

    void zero(function<void(int)> printNumber) {
        while (count <= n) {
            unique_lock<mutex> lck(mtx);
            cvZero.wait(lck, [this]() {return next == -1; });
            if (count <= n) {
                printNumber(0);
            }
            next = count % 2;
            lck.unlock();
            cvEven.notify_one();
            cvOdd.notify_one();
        }

        return;
    }

    void even(function<void(int)> printNumber) {
        while (count <= n) {
            unique_lock<mutex> lck(mtx);
            cvEven.wait(lck, [this]() {return next == 0; });
            if (count <= n) {
                printNumber(count);
            }
            count++;
            next = -1;
            lck.unlock();
            cvZero.notify_one();
        }
        return;
    }

    void odd(function<void(int)> printNumber) {
        while (count <= n) {
            unique_lock<mutex> lck(mtx);
            cvOdd.wait(lck, [this]() {return next == 1; });
            if (count <= n) {
                printNumber(count);
            }
            count++;
            next = -1;
            lck.unlock();
            cvZero.notify_one();
        }
        return;
    }
};

void test_1116()
{
    ZeroEvenOdd f(1000);
    std::jthread t1(&ZeroEvenOdd::zero, &f, [](int number) { std::cout << number; });
    std::jthread t2(&ZeroEvenOdd::even, &f, [](int number) { std::cout << number; });
    std::jthread t3(&ZeroEvenOdd::odd,  &f, [](int number) { std::cout << number; });
}
