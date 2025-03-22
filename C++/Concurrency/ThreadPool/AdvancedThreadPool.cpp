// AdvancedThreadPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <assert.h>
#include <future>

#include "..\common\Lock_free_queue.h"
#include "..\common\thread_safe_queue.h"
#include "..\common\common_threadsafe_queue.h"

const unsigned int COUNT = 10'000'000;
const unsigned int REPS = 10;

using namespace std;
using namespace std::chrono;

class thread_pool
{
public:
	thread_pool(unsigned int threads = std::thread::hardware_concurrency())
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
				if (!f && !m_queues[i].pop(f)) break;
				f();
			}
		};
		for (unsigned int i = 0; i < threads; ++i)
			m_threads.emplace_back(worker, i);
	}

	~thread_pool() noexcept
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

int main()
{
	//srand(0);
	//auto start = high_resolution_clock::now();
	//{
	//	simple_thread_pool tp;
	//	for (int i = 0; i < COUNT; ++i)
	//		tp.enqueue_work([i]() {
	//		int x;
	//		int reps = REPS + (REPS * (rand() % 5));
	//		for (int n = 0; n < reps; ++n)
	//			x = i + rand();
	//			});
	//}
	//auto end = high_resolution_clock::now();
	//auto duration = duration_cast<milliseconds>(end - start);
	//cout << "simple_thread_pool duration = " << duration.count() / 1000.f << " s" << endl;

	srand(0);
	auto start = high_resolution_clock::now();
	{
		thread_pool tp;
		for (int i = 0; i < COUNT; ++i)
			tp.enqueue_work([i]() {
			int x;
			int reps = REPS + (REPS * (rand() % 5));
			for (int n = 0; n < reps; ++n)
				x = i + rand();
				});
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "thread_pool duration = " << duration.count() / 1000.f << " s" << endl;
}

