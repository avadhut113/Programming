// ParallelAccumulate_Async.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>
#include <numeric>
#include <chrono>
#include <algorithm>

int MIN_ELE_COUNT = 1000;

template<typename iterator>
int parallel_accumulate(iterator begin, iterator end)
{
  long len = std::distance(begin, end);

  if (len <= MIN_ELE_COUNT) {
    //std::cout << std::this_thread::get_id() << std::endl;
    return std::accumulate(begin, end, 0);
  }

  iterator mid = begin;
  std::advance(mid, (len + 1) / 2);

  std::future<int> f1 = std::async(std::launch::async, parallel_accumulate<iterator>, mid, end);

  auto sum = parallel_accumulate(begin, mid);
  return sum + f1.get();
}


int main()
{
  const int size = 800000;
  std::vector<int> vect(size);

  srand(0);

  for (size_t i = 0; i < size; i++) {
    vect[i] = rand() % 10;
  }

  auto start = std::chrono::high_resolution_clock::now();
  int result_val = parallel_accumulate<std::vector<int>::iterator>(vect.begin(), vect.end());
  std::cout << "parallel accumulate value: " << result_val << std::endl;
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "parallel accumulate execution time : " << duration.count() << std::endl;



  auto start_1 = std::chrono::high_resolution_clock::now();
  std::cout << "std accumulate value: " << std::accumulate(vect.begin(), vect.end(), 0) << std::endl;
  auto stop_1 = std::chrono::high_resolution_clock::now();
  auto duration_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1 - start_1);
  std::cout << "std accumulate execution time : " << duration_1.count() << std::endl;



}
