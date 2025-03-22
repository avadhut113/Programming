// Package_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>
#include <string>

int add(int x, int y, std::string str)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << str  << " : " << std::this_thread::get_id() << std::endl;
  return x + y;
}

void pkg_task_thread()
{
  std::packaged_task<int(int, int, std::string)> task1(add);
  std::future<int> f1 = task1.get_future();

  std::thread t(std::move(task1), 6, 7, "task thread");
  t.detach();

  std::cout << "task Thread Add : " << f1.get() << std::endl;

}

void pkg_task_normal()
{
  std::packaged_task<int(int, int, std::string)> task2(add);
  std::future<int> f2 = task2.get_future();

  task2(5, 6, "Task Normal");

  std::cout << "task Normal Add : " << f2.get() << std::endl;
}

int main()
{
  std::cout << " Main Thread : " << std::this_thread::get_id() << std::endl;
  pkg_task_normal();
  pkg_task_thread();
}

