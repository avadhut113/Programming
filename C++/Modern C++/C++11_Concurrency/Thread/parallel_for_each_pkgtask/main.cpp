#include <iostream>
#include <chrono>
#include <execution>

#include "parallel_for_each_pkgtask_async.h"
#include "..\utils.h"

const size_t test_size = 10000;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;

int main()
{

  std::vector<int> vect(test_size);

  for (unsigned int i = 0; i < test_size; i++) {
    vect[i] = 1;
  }

  auto long_fun = [](const int& n) {
    int sum = 0;

    for (auto i = 0; i < 10000; i++) {
      sum += 1 * (i - 499);
    }
  };


  auto start = high_resolution_clock::now();
  std::for_each(vect.cbegin(), vect.cend(), long_fun);
  auto end = high_resolution_clock::now();
  print_results("Stl :", start, end);

  start = high_resolution_clock::now();
  std::for_each(std::execution::seq , vect.cbegin(), vect.cend(), long_fun);
  end = high_resolution_clock::now();
  print_results("Stl-seq :", start, end);

  start = high_resolution_clock::now();
  std::for_each(std::execution::par, vect.cbegin(), vect.cend(), long_fun);
  end = high_resolution_clock::now();
  print_results("Stl-par :", start, end);

  start = high_resolution_clock::now();
  parallel_for_each_pt(vect.cbegin(), vect.cend(), long_fun);
  end = high_resolution_clock::now();
  print_results("parallel_for_each_pt :", start, end);

  start = high_resolution_clock::now();
  parallel_for_each_async(vect.cbegin(), vect.cend(), long_fun);
  end = high_resolution_clock::now();
  print_results("parallel_for_each_async :", start, end);



  return 0;
}