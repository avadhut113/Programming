// Constness.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class demo
{
  int var = 100;
  const int iConst = 0;
public:
  static int stat_var;
  demo(int v, int c) : var(v), iConst(c) {

  }
  //int getvar() const {

  //  //const_cast<demo*>(this)->var = 200;
  //  std::cout << "const fun" << std::endl;
  //  return var;
  //}

  int getvar() {
    std::cout << "non-const fun" << std::endl;
    return var;
  }

  static int getstat_ver() {
    return stat_var;
  }

};

int demo::stat_var = 150;

int main()
{
  int i = 10;
  int* const ptr = &i;

  *ptr = 20;
  std::cout << i << std::endl;

  const int j = 5;
  const int * ptrj = &j;
  const_cast<int&>(j) = 7;
  std::cout << j << std::endl;

  demo d1(10, 20);
  std::cout << d1.getvar() << std::endl;
  std::cout << d1.stat_var << std::endl;

  const demo d(100, 200);
  std::cout << d.getvar() << std::endl;
  std::cout << d.stat_var << std::endl;
  
}

