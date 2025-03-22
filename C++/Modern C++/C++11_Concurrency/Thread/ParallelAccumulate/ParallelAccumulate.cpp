// ParallelAccumulate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <chrono>

using namespace std::chrono;

#define MIN_BLOCK_SIZE 1000

template<typename iterator, typename T>
void accumulate(iterator start, iterator end, T& ref)
{
  ref = std::accumulate(start, end, 0);
}

template<typename iterator, typename T>
T parallel_accumulate(iterator start, iterator end, T& ref)
{
  int input_size = std::distance(start, end);
  int allow_thread_by_elem = (input_size) / MIN_BLOCK_SIZE;

  int allow_thread_by_hardware = std::thread::hardware_concurrency();

  int num_thread = std::min(allow_thread_by_elem, allow_thread_by_hardware);

  int block_size = (input_size + 1) / num_thread;

  std::vector<T> result(num_thread);
  std::vector<std::thread> threads(num_thread - 1);

  iterator last;

  for (int i = 0; i < num_thread - 1; i++) {
    last = start;
    std::advance(last, block_size);
    threads[i] = std::thread(accumulate<iterator, T>, start, last, std::ref(result[i]));

    start = last;
  }

  result[num_thread - 1] = std::accumulate(start, end, 0);

  std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

  return std::accumulate(result.begin(), result.end(), 0);
}

int main()
{
  const int size = 80000000;
  int* my_arr = new int[size];
  int ref = 0;

  srand(0);

  for (size_t i = 0; i < size; i++) {
    my_arr[i] = rand() % 10;
  }

  auto start = high_resolution_clock::now();
  int result_val = parallel_accumulate<int*, int>(my_arr, my_arr + size, ref);
  std::cout << "parallel accumulate value: " << result_val << std::endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << "parallel accumulate execution time : " <<duration.count() << std::endl;



  auto start_1 = high_resolution_clock::now();
  std::cout << "std accumulate value: " << std::accumulate(my_arr, my_arr + size, 0) << std::endl;
  auto stop_1 = high_resolution_clock::now();
  auto duration_1 = duration_cast<microseconds>(stop_1 - start_1);
  std::cout << "std accumulate execution time : " << duration_1.count() << std::endl;

  delete[] my_arr;
}
