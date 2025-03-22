#include<iostream>
#include<thread>
#include<string>
using namespace std;

class functor
{
public:
  void operator()(int i) {
    while (i-- > 0) {
      cout << "functor : " << i << endl;
    }
  }
};

void run(int i)
{
  while (i-- > 0) {
    cout << "fun ptr :" << i << endl;
  }
}

class _non_stat_
{
public:
  void run(int i) {
    while (i-- > 0) {
      cout << "non-static : "<< i << endl;
    }
  }
};

class _stat_
{
public:
  static void run(int i) {
    while (i-- > 0) {
      cout << "Static : " << i << endl;
    }
  }
};

class base
{
  int b;
public:
  base(int i) : b(i) {}
  virtual void print() {
    cout << "base : " << b << endl;
  }
};

class child : public base
{
  int c;
public:
  child(int i) : c(i), base(0) {}
  void print() {
    cout << "child : " << c << endl;
  }
};


int main()
{
  /*thread t1(run,2);
  auto fun = [](int i) {
    while (i-- > 0) {
      cout << "lambda : " << i << endl;
    }
  };
  thread t2(fun, 2);
  functor f;
  thread t3(f, 2);
  _non_stat_ ns;
  thread t4(&_non_stat_::run, ns, 2);
  thread t5(&_stat_::run, 2);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();*/

  base* ptr = new child(5);

  thread t(&base::print, ptr);

  t.join();
  return 1;
}