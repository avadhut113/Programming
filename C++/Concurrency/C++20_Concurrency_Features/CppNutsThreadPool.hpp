#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>

class  CppNutsThreadPool
{
public:
	CppNutsThreadPool() : stop_flag(false){
		for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {
			workerThreads.emplace_back([this] {
				std::unique_lock<std::mutex> ul(queueMutex);
				cond.wait(ul, [this] { return stop_flag || !tasks.empty(); });
				
				if (stop_flag && tasks.empty())
					return;

				auto task = std::move(tasks.front());
				tasks.pop();
				ul.unlock();
				task();
			});
		}
	}

	template <class func>
	void enqueueTask(func&& task) {
		std::unique_lock<std::mutex> ul(queueMutex);
		tasks.emplace(std::forward<func>(task));
		ul.unlock();
		cond.notify_one();
	}

	~CppNutsThreadPool() {
		std::unique_lock<std::mutex> ul(queueMutex);
		stop_flag = true;
		ul.unlock();
		cond.notify_all();
	}

private:
	std::vector<std::jthread> workerThreads;
	std::queue<std::function<void()>> tasks;

	std::mutex queueMutex;
	std::condition_variable cond;
	bool stop_flag{ false };
};

std::string get_thread_id()
{
	auto myid = std::this_thread::get_id();
	std::stringstream ss;
	ss << myid;
	std::string  str = ss.str();
	return str;
}

void testCppNutsThreadPool()
{
	CppNutsThreadPool pool;

	std::cout << "Created thred Pool\n";
	std::cout << "Enqueue some tasks\n";

	for (int i = 0; i < 8; i++) {
		pool.enqueueTask([i] {
			std::cout << "task " << i << " is Executed by " << get_thread_id() << "\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		});
	}
}