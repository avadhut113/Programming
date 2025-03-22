// Class_Template_Explicit_Specialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
class prettyPrinter{
  T *ptr;
public:
  prettyPrinter(T* p) : ptr(p) {

  }

  void print() {
    std::cout << "{" << *ptr << "}" << std::endl;
  }

  T* GetPtr() {
    return ptr;
  }
};

int main()
{
  int data = 5;
  char* c{ "Hello world" };

  prettyPrinter<char*> p(&data);
  p.print();

  char* gp = p.GetPtr();
}

