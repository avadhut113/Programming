// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template<class T>
T Max(T x, T y)
{
  std::cout << typeid(T).name() << std::endl;
  return x > y ? x : y;
}

//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specializarion
template<> const char* Max(const char* a, const char* b) {
  std::cout << "Explicit Specializarion" << std::endl;
  return strcmp(a, b) > 0 ? a : b;
}

//Non-type templates
template<int N>
void print()
{
  if (N > 0) {
    std::cout << N << std::endl;

    
    //print<N - 1>(); will not work always need const expr 
  }
    
}


int main()
{
  std::cout << Max(5, 2) << std::endl;
  std::cout << Max('a','b') << std::endl;

  //Type deduction overriding
  std::cout << Max<int>('a', 'b') << std::endl;
  std::cout << Max<double>(3, 3.5) << std::endl;

  //cast to perform type deduction
  std::cout << Max(static_cast<double>(3), 3.5) << std::endl;

  //function pointer to template

  int(*funptr)(int, int) = Max;
  std::cout << funptr(5, 5.5) << std::endl;
  

  std::cout << Max("A","B") << std::endl;

  print<100>();
}


