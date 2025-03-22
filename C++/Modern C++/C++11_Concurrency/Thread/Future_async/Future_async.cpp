// Future_async.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>


void printing()
{
  std::cout << "printing from the thread : " << std::this_thread::get_id() << std::endl;
}

int addition(int x, int y) {
  std::cout << "addition from the thread : " << std::this_thread::get_id() << std::endl;
  return x + y;
}

int sunstract(int x, int y) {
  std::cout << "sunstract from the thread : " << std::this_thread::get_id() << std::endl;
  return x - y;
}

int main()
{
  std::cout << "main thread id : " << std::this_thread::get_id() << std::endl;
  int x = 100, y = 200;
  std::future<void> f1 = std::async(std::launch::async, printing);
  auto f2 = std::async(std::launch::deferred, addition, x, y);
  auto f3 = std::async(std::launch::async | std::launch::deferred, sunstract, x, y);

  f1.get();
  std::cout << "value received from f2 : " << f2.get() << std::endl;
  std::cout << "value received from f3 : " << f3.get() << std::endl;
}

