// future_promise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<future>


using namespace std;

int factorial_fun(std::future<int>& fu)
{
  int res = 1;
  int factno = fu.get();
  for (int i = 1; i <= factno ; i++)
    res = res * i;

  return res;
}

int main()
{
  std::promise<int> p;
  std::future<int> fu1 = p.get_future();

  std::future<int> fu = std::async(factorial_fun, std::ref(fu1));
  p.set_value(5);
  //p.set_exception(std::make_exception_ptr(std::runtime_error("Promise has been broken")));
  cout << "factorial of is " << fu.get();
}

