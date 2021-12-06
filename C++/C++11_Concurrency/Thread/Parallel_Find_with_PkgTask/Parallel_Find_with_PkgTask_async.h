#include <iostream>
#include <thread>
#include <atomic>
#include <future>

#include "..\common.h"

using ulong_const = unsigned long const;

template<typename Iterator, typename MatchType>
Iterator parallel_find_pkgtask(Iterator begin, Iterator end, MatchType match)
{

  struct find_element
  {
    void operator()(Iterator begin, Iterator end, MatchType match, std::promise<Iterator>* result, std::atomic<bool>* done_flag) {
      try {
        for (; begin != end && !std::atomic_load(done_flag); begin++) {
          if (*begin == match) {
            result->set_value(begin);
            std::atomic_store(done_flag, true);
            return;
          }
        }
      }
      catch (...) {
        result->set_exception(std::current_exception());
        done_flag->store(true);
      }
    }
  };

  ulong_const length = std::distance(begin, end);
  if (!length)
    return end;

  ulong_const min_ele_per_thrd = 25;
  ulong_const max_thread    = (length + min_ele_per_thrd - 1) / min_ele_per_thrd;

  ulong_const hardware_thrd = std::thread::hardware_concurrency();
  ulong_const num_thread    = std::min(hardware_thrd != 0 ? hardware_thrd : 2, max_thread);
  ulong_const block_size = length / num_thread;

  std::promise<Iterator> result;
  std::atomic<bool> done_flag(false);

  std::vector<std::thread> threads(num_thread - 1);

  join_threads joiner(threads);

  Iterator block_start = begin;
  for (unsigned long i = 0; i < num_thread - 1; i++) {

    Iterator block_end = block_start;
    std::advance(block_end, block_size);

    threads[i] = std::thread(find_element(), begin, end, match, &result, &done_flag);

    block_start = block_end;
  }

  find_element()(begin, end, match, &result, &done_flag);

  if (!done_flag.load())
    return end;

  return result.get_future().get();

}

template<typename Iterator, typename MatchType>
Iterator parallel_find_asyc(Iterator begin, Iterator end, MatchType match, std::atomic<bool>* done_flag)
{
  try {

    ulong_const length = std::distance(begin, end);
    ulong_const min_ele_per_thrd = 25;

    if (min_ele_per_thrd < 2 * length) {
      for (; begin != end && done_flag; begin++) {
        if (*begin == match) {
          *done_flag = true;
          return begin;
        }
      }
    }
    else {
      Iterator const mid = begin + length / 2;
      std::future<Iterator> async_result = std::async(parallel_find_asyc<Iterator, MatchType>, mid, end, match, std::ref(done_flag));

      Iterator const direct_result = parallel_find_asyc(begin, end, match, done_flag);

      return (direct_result == mid ? async_result.get() : direct_result);
    }

  }
  catch (...) {
    *done_flag = true;
    throw;
  }
}