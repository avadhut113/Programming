#include "SimpleThreadPool.hpp"
#include "AdvancedThreadPool.hpp"
#include "ThreadPool_WaitingThreads.hpp"
#include "ZenThreadPool.h"


void Checksum(const std::uint32_t num, std::atomic_uint64_t* checksum)
{
	*checksum += num;
}

void simple_theadpool_test()
{
	auto start = high_resolution_clock::now();
	{
		Simplethread_pool pool;
		for (int i = 0; i < 100; i++) {
			pool.submit([=] {
				printf("%d printed by thrad - %d \n", i, std::this_thread::get_id());
				}
			);
		}
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "simple_thread_pool duration = " << duration.count() / 1000.f << " s" << endl;
	system("pause");
}

void waiting_threadpool_test()
{
	auto start = high_resolution_clock::now();
	{
		WaitingThreadPool pool;
		for (int i = 0; i < 100; i++) {
			pool.submit([=] {
				printf("%d printed by thread - %d \n", i, std::this_thread::get_id());
				}
			);
		}
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "waiting_thread_pool duration = " << duration.count() / 1000.f << " s" << endl;
	system("pause");
}

void advance_threadpool_test()
{
	srand(0);
	auto start = high_resolution_clock::now();
	{
		AdvanceThreadPool tp;
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
	cout << "advance thread_pool duration = " << duration.count() / 1000.f << " s" << endl;
}

void zen_threadpool_test()
{
	ZenThreadPool thread_pool{ 4 };
	std::queue<std::future<void>> results;
	std::atomic_uint64_t checksum{ 0 };
	std::uint64_t localChecksum{ 0 };

	for (std::uint32_t n = 0; n < 1000; ++n)
	{
		results.emplace(thread_pool.AddTask(Checksum, n, &checksum));
		localChecksum += n;
	}
	while (results.size())
	{
		results.front().get();
		results.pop();
	}

	if (checksum == localChecksum)
		std::cout << "Working fine";
}

int main()
{
	zen_threadpool_test();
}