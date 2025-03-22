// Concurrency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <print>
#include <thread>
#include <atomic>
#include <chrono>
#include <future>
#include <numeric>
#include <latch>


#include "Barrier_main.hpp"
#include "Semaphores.hpp"
#include "CppNutsThreadPool.hpp"
#include "ZenThreadPool.hpp"

using namespace std::literals::chrono_literals;

void spin_bool_foo(std::atomic<bool>& flag)
{
	while (flag.exchange(true)) {

	}

	std::cout << "Worker spin lock opend doing stuff \n";
	std::cout << "Worker realeasing lock \n";

	flag = false;
}


void volatile_test()
{
	int y = 1;
	volatile int* x = &y;

	auto w = std::jthread([x]() {
		for (int i = 0; i < 50; i++)
			*x += 1;
		});

	auto r = std::jthread([x]() {
		for (int i = 0; i < 50; i++)
			//std::println("{}\n", *x);
			std::cout << *x << std::endl;
		});
}

void test_future_promise()
{
	std::promise<int> p;

	std::jthread([&p]() {
		for (int i = 0; i < 3; i++) {
			std::cout << "wait for promise in thread : " << std::this_thread::get_id() << "\n";
			std::this_thread::sleep_for(1s);
		}
		p.set_value(42);
		});

	std::jthread([](auto f) {
		std::cout << "the value promised : " << f.get() <<"\n";
		}, p.get_future());
}

void test_future_promise_accumulate()
{
	std::promise<int> p1, p2;
	auto future = p1.get_future();
	std::vector number{ 500 };
	std::iota(number.begin(), number.end(), 0);

	auto sumthread = std::jthread([&p1, &number]() {
		auto sum = std::accumulate(number.begin(), number.end(),0);
		p1.set_value(sum);
	});

	auto dothread = std::jthread([&p2, &future]() {
		auto sum = future.get();
		p2.set_value(sum > 100 ? sum / 2 : sum + 200);
	});

	std::cout << " sum : " << p2.get_future().get() << "\n";
}

void test_spin_lock()
{
	std::atomic<bool> flag{ true };
	auto holder = std::jthread([&flag]() {
		std::this_thread::sleep_for(1s);
		std::cout << "Holder releasing a lock \n";
		flag = false;
		});

	auto worker = std::jthread(spin_bool_foo, std::ref(flag));
}

void printString()
{
	int i = 10;
	i = i + 1;
	std::cout << i << "\n";
}


int main() {
	//volatile_test();

	//test_spin_lock();

	//test_future_promise();

	//test_future_promise_accumulate();

	//test_semaphore();

	//test_latches();

	//test_barrier();

	//testCppNutsThreadPool();

	//testZenThreadPoolUsingTask();

	std::jthread t1(printString);
	std::jthread t2(printString);
	std::jthread t3(printString);
	std::jthread t4(printString);
	std::jthread t5(printString);

}