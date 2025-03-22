// Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template<typename T>
T Max(T a, T b)
{
  std::cout << typeid(T).name() << std::endl;
  return a > b ? a : b;
}

// Explicit instanciation
template char Max(char a, char b);

//Explicit Specialization
template<> const char* Max<const char*>(const char* a, const char* b)
{
  std::cout << "Max<const char*>" << std::endl;
  return strcmp(a, b) > 0 ? a : b;
}


//non type template  = N
template<int N>
void sum()
{
  std::cout << N << std::endl;
  sum<N - 1>();
}

template<>
void sum<1>()
{
  std::cout << 1 << std::endl;
}




int main()
{
  sum<10>();

  std::cout << Max(5, 7) << std::endl;
  std::cout << Max<double>(5.9, 7) << std::endl;
  std::cout << Max(static_cast<double>(5), 7.3) << std::endl;

  long(*fptr)(long, long) = Max;

  const char *a = "ABCD";
  const char *b = "XYZ";
  std::cout << Max(a,b) << std::endl;
}



