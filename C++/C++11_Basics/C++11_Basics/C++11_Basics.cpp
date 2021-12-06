// C++11_Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//move semantics
#include <iostream>
#include <initializer_list>
#include <typeinfo>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <algorithm>

class arr
{
  int* ptr;
  int size;
public:
  arr(int size) {
    this->size = size;
    ptr = new int[size];

    for (int i = 0; i < size; i++) {
      ptr[i] = i;
    }
  }
  arr(const arr& obTest) {
    this->size = obTest.size;
    this->ptr = new int[this->size];
    for (int i = 0; i < this->size; i++) {
      this->ptr[i] = obTest.ptr[i];
    }
    std::cout << "copy" << std::endl;
  }
  arr(arr&& obtest) {
    this->size = obtest.size;
    this->ptr  = obtest.ptr;
    obtest.size = 0;
    obtest.ptr = nullptr;

    std::cout << "move" << std::endl;
  }

  //initializer list constructor
  arr(const std::initializer_list<int>& list) {
    
    //foreach
    //int i = 0;
    //for (std::initializer_list<int>::iterator itr = list.begin(); itr != list.end(); itr++) {
    //  ptr[i] = *itr;
    //}
    ptr = new int[list.size()];
    size = 0;
    for (auto& itr : list) {
      ptr[size] = itr;
      size++;
    }
  }
};

class base
{
  int b = 10;
public:
  int k;
  base(int i = 10) : b(i) {}
  base(const base& obj) : b(obj.b) {
    std::cout << __FUNCTION__ << std::endl;
  }
  virtual void fun() {
    std::cout << __FUNCTION__ << std::endl;
  }
  ~base(){}
};

class child :private base
{
  int c;
public:
  child(int c, int b) : c(c), base(b) {
    b = 10;
    k = 20;
    base::fun();
  }
  void fun()  {
    std::cout << __FUNCTION__ << std::endl;
  }
};


//perfect forwarding
template<typename T>
void PerfectForward(T&& UniRef) {
  FuncFoo(std::forward<T&&>(UniRef));
}

void FuncFoo(arr&& t) {

}

arr createarr(int size) {
  return arr(size);
}

void array()
{
  std::array<int, 7> a{ 1,2,3,4,5 };
  std::array<int, 7> a1{ 11,21,101,41,51, 61, 71 };
  a[3] = 123;
  std::cout << "a[3] : " << a[3] << std::endl;
  std::cout << "size : " << a.size() << std::endl;
  std::cout << "empty :" << a.empty() << std::endl;
  std::cout << "begin : " << *(a.begin()+2) << std::endl;
  std::cout << "end : " << *(a.end() - 1) << std::endl;
  std::cout << "back : " << a.back() << std::endl;
  std::cout << "max size : " << a.max_size() << std::endl;
  a.swap(a1);

  std::sort(a.begin(), a.end(), [](auto x, auto y) {return x > y; });
  for (auto i : a) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  for (auto i : a1) {
    std::cout << i << " ";
  }
}

void vector()
{
  std::vector<int> vect = { 11,12,13,14, 15, 16, 17 };

  std::vector<base> vect_base;

  vect_base.reserve(3);

  vect_base.push_back(1);
  vect_base.push_back(2);
  vect_base.push_back(3);




  std::cout << "capacity : " << vect.capacity() << std::endl;
  std::cout << "size : " << vect.size() << std::endl;
  std::cout << "Data : " << *(vect.data()) << std::endl;
  std::cout << "" << vect.front() << std::endl;
  //vect.emplace()

  std::vector<base> vect_base1;

  vect_base1.reserve(3);

  vect_base1.emplace_back(1);
  vect_base1.emplace_back(2);
  vect_base1.emplace_back(3);

  
}

void list()
{
  std::list<int> lt{1,2,3,4,5};
  std::list<int> lt2{ 11,12,13,14,15 };
  auto itr = lt2.begin();
  lt.splice(lt.begin(), lt2, itr);

  for (auto i : lt) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (auto i : lt2) {
    std::cout << i << " ";
  }

}

class Base
{
public:
  int d = 20;
  void fun();
};

void Base::fun() 
{
  std::cout << "common code" << std::endl;
}

class Derive1 :public Base
{
public:
  int d = 10;
  void fun()
  {
    Base::fun();
    std::cout << "Derive fun" << std::endl;
  }
};

class Derive2 :public Base
{
public:
  int d = 5;
  void fun()
  {
    Base::fun();
    std::cout << "Derive fun" << std::endl;
  }
};

void map()
{
  
  std::multimap<int, std::string, std::greater<int>> mp;

  auto a = [](int x, int y) {return x > y; };
  mp.insert({ { 1, "abc" }, {2 , "xyz"},{3 , "pqr"},{3 , "ppqqrr"},{4 , "lmn" } });

  for (auto ele : mp) {
    std::cout << ele.first << " " << ele.second << std::endl;
  }

  auto found = mp.equal_range(3);
  while (found.first != found.second) {
    std::cout << found.first->first << " " << found.first->second << std::endl;
    found.first++;
  }
}

void printseqcount()
{
  const char* str = "Hellolllee";

  int count = 0;
  while (*str != '\0') {
    count = 1;
    while (*str == *(str + 1)) {
      str++;
      count++;
    }
    if (count > 1)
      std::cout << *str << " : " << count << std::endl;
    str++;
  }
}

int main()
{


  Derive1* b = new Derive1();
  Derive1* b1 = b + 1;

  char* c1 = reinterpret_cast<char*>(b);
  char* c2 = reinterpret_cast<char*>(b1);
  std::cout << int(c2-c1) << std::endl;

  std::cout << b->d << std::endl;
  b->fun();
  //arr a = { 1,2,3,4 };
  //PerfectForward(a);
  //PerfectForward(std::move(a));

  //base* b = new child();
  //child* c = dynamic_cast<child*>(b);

  //c->fun();
  //const type_info& t = typeid(c);
  //std::cout << typeid(c).name() << std::endl;

  //for (auto i : { 1,2,3,4,5 }) {

  //  i += 3;
  //  std::cout << i;
  //}


  //array();
  //vector();
  //list();
  //map();
}

