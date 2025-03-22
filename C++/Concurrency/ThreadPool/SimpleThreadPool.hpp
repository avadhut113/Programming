// ThreadPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atomic>
#include <vector>
#include <functional>
#include "..\common\Lock_free_queue.hpp"
#include "..\common\thread_safe_queue.hpp"
#include "..\common\common_threadsafe_queue.hpp"
#include "ThreadJoiner.hpp"

class Simplethread_pool
{
public:
	void do_work()
	{
		while (!done) {
			std::shared_ptr<std::function<void()>> task_ptr = worker_queue.pop();
			if (task_ptr) {
				(*task_ptr)();
			}
			else
				std::this_thread::yield();
		}
	}

	Simplethread_pool() :done(false),joiner(threads)
	{

		int max_thread = std::thread::hardware_concurrency();

		try {
			for (int i = 0; i < max_thread; i++) {
				threads.emplace_back(std::thread(&Simplethread_pool::do_work, this));
			}
		}
		catch (...) {
			done = true;
			throw;
		}
	}

	template<typename function_name>
	void submit(function_name func) 
	{
		worker_queue.push(std::function<void()>(func));
	}

private:
	std::atomic_bool done;
	sequential_queue5<std::function<void()>> worker_queue;
	std::vector<std::thread> threads;
	join_threads joiner;
};

/*class thread_pool
{
	std::atomic_bool done;
	threadsafe_queue<std::function<void()>> work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;

	void worker_thread()
	{
		while (!done)
		{
			std::function<void()> task;
			if (work_queue.try_pop(task))
			{
				task();
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}

public:
	thread_pool() :done(false), joiner(threads)
	{
		int const thread_count = std::thread::hardware_concurrency();

		try
		{
			for (int i = 0; i < thread_count; i++)
			{
				threads.push_back(
					std::thread(&thread_pool::worker_thread, this));
			}
		}
		catch (...)
		{
			done = true;
			throw;
		}
	}

	~thread_pool()
	{
		done = true;
	}

	template<typename Function_type>
	void submit(Function_type f)
	{
		work_queue.push(std::function<void()>(f));
	}
};*/


class test
{
	static int i;
public:
	test(int _i)
	{
		i = _i;
	}

	 void set(int _i) {
		i = _i;
	}

	static int get() {

	}
};

int test::i = 0;


