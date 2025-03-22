// Parallel_Find_with_PkgTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <future>

#include "..\common.h"

using ulong_const = unsigned long const;

template<typename Iterator, typename Func>
void parallel_for_each_pt(Iterator begin, Iterator end, Func fun)
{
  ulong_const length = std::distance(begin, end);

  if (!length)
    return;

  ulong_const min_ele_per_thrd = 25;
  ulong_const max_thrd = (length + min_ele_per_thrd - 1) / min_ele_per_thrd;

  ulong_const hardware_thrd = std::thread::hardware_concurrency();
  ulong_const num_thrd = std::min(hardware_thrd != 0 ? hardware_thrd : 2, max_thrd);
  ulong_const block_size = length / num_thrd;


  std::vector<std::future<void>> futures(num_thrd - 1);
  std::vector<std::thread> threads(num_thrd - 1);

  join_threads joiners(threads);

  Iterator block_start = begin;

  for (unsigned long i = 0; i <= (num_thrd - 2); i++) {

    Iterator block_end = block_start;
    std::advance(block_end, block_size);

    std::packaged_task<void(void)> pkg_task(
      [=]() {
      std::for_each(block_start, block_end, fun);
    }
    );

    futures[i] = pkg_task.get_future();
    threads[i] = std::thread(std::move(pkg_task));

    block_start = block_end;

  }

  //call the function for last block
  std::for_each(block_start, end, fun);

  //wait until future ready
  for (unsigned int i = 0; i < (num_thrd - 1); i++)
    futures[i].get();
}

template<typename Iterator, typename Func>
void parallel_for_each_async(Iterator begin, Iterator end, Func fun)
{
  ulong_const length = std::distance(begin, end);

  if (!length)
    return;

  ulong_const min_per_thread = 25;

  if (length < 2 * min_per_thread) {
    std::for_each(begin, end, fun);
  }
  else {
    Iterator const midpoint = begin + length / 2;

    std::future<void> first_half = std::async(std::launch::async, &parallel_for_each_async<Iterator, Func>, begin, midpoint, fun);

    parallel_for_each_async(midpoint, end, fun);

    first_half.get();

  }
}


