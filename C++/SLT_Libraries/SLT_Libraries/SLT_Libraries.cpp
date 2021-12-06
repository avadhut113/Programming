// SLT_Libraries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <functional>
//------------------------------------------------Functors-------------------------------------------------------------


class Power
{
  int exp;
public:
  Power(int b) : exp(b) {}
  int operator()(int base) {
    return pow(base,exp);
  }
};

int add2(int& a) {
  return a + 2;
}


int main()
{
  Power P(3);
  int Cube_num = P(2);
  //std::cout << Cube_num << std::endl;
  //std::cout << Power(4)(2) << std::endl;

  std::vector<int> Myset = { 1,2,3,4,5 };
  std::vector<int> vect;

  int x = std::multiplies<int>()(3, 4);
  std::plus<int>();

  std::transform(Myset.begin(), Myset.end(), std::back_inserter(vect),  bind(std::multiplies<int>(), std::placeholders::_1, 10));

  for (auto i : vect) {
    std::cout << i << std::endl;
  }

  std::for_each(vect.begin(), vect.end(), add2);
  for (auto i : vect) {
    std::cout << i << std::endl;
  }
    
}