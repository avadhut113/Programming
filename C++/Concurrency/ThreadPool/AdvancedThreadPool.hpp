// AdvancedThreadPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <assert.h>
#include <future>

#include "..\common\Lock_free_queue.hpp"
#include "..\common\thread_safe_queue.hpp"
#include "..\common\common_threadsafe_queue.hpp"

const unsigned int COUNT = 10'000'000;
const unsigned int REPS = 10;

using namespace std;
using namespace std::chrono;

class AdvanceThreadPool
{
public:
	AdvanceThreadPool(unsigned int threads = std::thread::hardware_concurrency())
		: m_queues(threads), m_count(threads)
	{
		assert(threads != 0);
		auto worker = [&](unsigned int i)
		{
			while (true)
			{
				Proc f;
				for (unsigned int n = 0; n < m_count; ++n)
					if (m_queues[(i + n) % m_count].try_pop(f)) break;
				if (!f && !m_queues[i].try_pop(f)) break;
				f();
			}
		};
		for (unsigned int i = 0; i < threads; ++i)
			m_threads.emplace_back(worker, i);
	}

	~AdvanceThreadPool() noexcept
	{
		for (auto& queue : m_queues)
			queue.done();
		for (auto& thread : m_threads)
			thread.join();
	}

	template<typename F, typename... Args>
	void enqueue_work(F&& f, Args&&... args)
	{
		auto work = [f, args...]() { f(args...); };
		unsigned int i = m_index++;
		for (unsigned int n = 0; n < m_count * K; ++n)
			if (m_queues[(i + n) % m_count].try_push(work)) return;
		m_queues[i % m_count].push(work);
	}

	template<typename F, typename... Args>
	auto enqueue_task(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
	{
		using return_type = typename std::result_of<F(Args...)>::type;
		auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
		std::future<return_type> res = task->get_future();

		auto work = [task]() { (*task)(); };
		unsigned int i = m_index++;
		for (unsigned int n = 0; n < m_count * K; ++n)
			if (m_queues[(i + n) % m_count].try_push(work)) return res;
		m_queues[i % m_count].push(work);

		return res;
	}

private:
	using Proc = std::function<void(void)>;
	using Queues = std::vector<threadsafe_queue<Proc>>;
	Queues m_queues;

	using Threads = std::vector<std::thread>;
	Threads m_threads;

	const unsigned int m_count;
	std::atomic_uint m_index = 0;

	inline static const unsigned int K = 3;
};


