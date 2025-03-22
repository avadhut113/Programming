// Barrier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <vector>
//#include <barrier>
//#include "BarrierConditional.hpp"
//#include "BarrierSpin.hpp"
//
//void fun(CBrierConditional& bar, std::atomic<int>& counter)
//{
//    ++counter;
//    bar.wait();
//    std::cout << "Current value after barrier : " << counter << std::endl;
//}
//
//void ConditionalBarrier()
//{
//    CBrierConditional bar(3);
//    std::atomic<int> counter;
//    std::thread t1(&fun, std::ref(bar), std::ref(counter));
//    std::thread t2(&fun, std::ref(bar), std::ref(counter));
//    std::thread t3(&fun, std::ref(bar), std::ref(counter));
//
//    t1.join();
//    t2.join();
//    t3.join();
//
//}
//
//void _fun(CBarrierSpin& bar, std::atomic<int>& counter)
//{
//    ++counter;
//    bar.wait();
//    std::cout << "Current value after barrier : " << counter << std::endl;
//}

//void SpinBarrier()
//{
//    CBarrierSpin bar(3);
//    std::atomic<int> counter;
//    std::thread t1(&_fun, std::ref(bar), std::ref(counter));
//    std::thread t2(&_fun, std::ref(bar), std::ref(counter));
//    std::thread t3(&_fun, std::ref(bar), std::ref(counter));
//
//    t1.join();
//    t2.join();
//    t3.join();
//
//}

//void test_barrier()
//{
//    std::vector<std::string_view> emp_name{ "Alex", "Dany", "benny", "Guy" };
//    std::vector<std::jthread> emp_thread;
//
//    auto on_complete = []() {
//        static int x = 0;
//        not x++ ? std::cout << "Go home\n" : std::cout << "Done!!\n";
//        };
//
//    std::barrier sync{ emp_name.size(), on_complete };
//
//    auto job = [&sync](std::string_view name) {
//            std::cout << name << " is doing job\n";
//            sync.arrive_and_wait();
//            std::cout << name << " is going home\n";
//            sync.arrive_and_wait();
//        };
//
//    for (const auto& emp : emp_name) {
//        emp_thread.emplace_back(std::jthread(job, emp));
//    }
//}