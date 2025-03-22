// static_keyword.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//global
static int i;

void fun() {
  //local
  static int i;
  i++;
}
class demo
{
public:
  static int i;
  int var;
  demo() {
    i++;
  }

  int getvar() {
    return var;
  }

  static int geti() {
    return i;
  }
};

int demo::i = 5;

int main()
{

  demo d;
  cout << d.getvar() << endl;
  cout << d.geti() << endl;

  //static object
  static demo sd;
  cout << sd.getvar() << endl;
  cout << sd.geti() << endl;
  cout << i << endl;
}
