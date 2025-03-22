// TLS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>

thread_local std::atomic<int> i;

void fun()
{
  i++;
  std::cout << i;
}
int main()
{
  std::thread t1(fun);
  std::thread t2(fun);
  std::thread t3(fun);

  t1.join();
  t2.join();
  t3.join();


}
