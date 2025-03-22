// Promise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <future>
#include <stdexcept>

void print_int(std::future<int>& f)
{
  std::cout << "Wating for value from main thread " << std::endl;
  std::cout << "result : " << f.get() << std::endl;
}

void print_sqrt(std::future<int>& f)
{
  try {

    std::cout << "Squere root is " << f.get() << std::endl;

  }
  catch (std::exception& e) {
    std::cout << "[Execption caught = " << e.what() << "]\n";
  }
}

void cal_sqrt(std::promise<int>& pm)
{
  try {

    int num = 0;
    std::cout << "enter num : ";
    std::cin >> num;
    if (num < 0)
      throw  std::invalid_argument("input cannot be negative");

    pm.set_value(sqrt(num));

  }
  catch (std::exception&) {
    pm.set_exception(std::current_exception());
  }
}

void print_val(std::future<int>& f)
{
  if (f.valid()) {
    std::cout << "Future is valid " << f.get() << std::endl;
  }
  else {
    std::cout << "Future is  not valid " << std::endl;
  }
}

int main()
{
  std::promise<int> pm;
  std::future<int> f1 = pm.get_future();

  //std::thread t(print_int, std::ref(f1));

  //std::this_thread::sleep_for(std::chrono::milliseconds(5000));

  //std::cout << "Setting value in main thread\n";
  //pm.set_value(12);

  std::thread t1(print_sqrt, std::ref(f1));
  std::thread t2(cal_sqrt, std::ref(pm));


  t1.join();
  t2.join();
}
