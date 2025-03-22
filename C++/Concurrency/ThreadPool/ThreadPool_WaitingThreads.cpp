// ThreadPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atomic>
#include <vector>
#include <functional>
#include <future>
#include "..\common\Lock_free_queue.h"
#include "..\common\thread_safe_queue.h"
#include "..\common\common_threadsafe_queue.h"

class join_threads {
	std::vector<std::thread>& threads;

public:
	explicit join_threads(std::vector<std::thread>& _threads) :
		threads(_threads)
	{}

	~join_threads()
	{
		for (long i = 0; i < threads.size(); i++)
		{
			if (threads[i].joinable())
				threads[i].join();
		}
	}
};

class thread_pool
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

	thread_pool() :done(false), joiner(threads)
	{

		int max_thread = std::thread::hardware_concurrency();

		try {
			for (int i = 0; i < max_thread; i++) {
				threads.emplace_back(std::thread(&thread_pool::do_work, this));
			}
		}
		catch (...) {
			done = true;
			throw;
		}
	}

	template<typename function_name>
	std::future<typename std::result_of<function_name()>::type> submit(function_name func)
	{
		worker_queue.push(std::function<void()>(func));
	}

private:
	std::atomic_bool done;
	sequential_queue5<std::function<void()>> worker_queue;
	std::vector<std::thread> threads;
	join_threads joiner;
};

int main()
{
	std::cout << "Totalthread : " << std::thread::hardware_concurrency() << std::endl;
	thread_pool pool;
	for (int i = 0; i < 100; i++) {
		pool.submit([=] {
			printf("%d printed by thrad - %d \n", i, std::this_thread::get_id());
			}
		);
	}
	system("pause");
}
