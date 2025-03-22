#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <execution>
#include <memory>

#include "Parallel_Find_with_PkgTask_async.h"
#include "..\common.h"
#include "..\utils.h"

const size_t testSize = 100000;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;

int main()
{

  std::vector<int> ints(testSize);
  for (size_t i = 0; i < testSize; i++)
  {
    ints[i] = i;
  }

  int looking_for = 45329;

  auto startTime = high_resolution_clock::now();
  std::find(ints.begin(), ints.end(), looking_for);
  auto endTime = high_resolution_clock::now();
  print_results("STL sequntial :", startTime, endTime);

  startTime = high_resolution_clock::now();
  std::find(std::execution::seq, ints.begin(), ints.end(), looking_for);
  endTime = high_resolution_clock::now();
  print_results("STL parallel-seq :", startTime, endTime);

  startTime = high_resolution_clock::now();
  std::find(std::execution::par, ints.begin(), ints.end(), looking_for);
  endTime = high_resolution_clock::now();
  print_results("STL parallel-par :", startTime, endTime);

  startTime = high_resolution_clock::now();
  auto value = parallel_find_pkgtask(ints.begin(), ints.end(), looking_for);
  endTime = high_resolution_clock::now();
  print_results("Parallel-package_task_impl :", startTime, endTime);

  startTime = high_resolution_clock::now();
  std::atomic<bool> done_flag(false);
  value = parallel_find_asyc(ints.begin(), ints.end(), looking_for, &done_flag);
  endTime = high_resolution_clock::now();
  print_results("parallel_find_asyc :", startTime, endTime);

  return 0;
}