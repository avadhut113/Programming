// smart_pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class Dog
{
  string name;
  //shared_ptr<Dog> pFriend; //Cyclic reference
  weak_ptr<Dog> pFriend;
public:
  Dog(string s = "nameless") : name(s) {
    cout << name << " created" << endl;
  }
  ~Dog() {
    cout << name << " Destroyed" << endl;
  }

  void makefriend(shared_ptr<Dog> f) { pFriend = f; }
  void ShowFriend() {
    if (!pFriend.expired()) {
      cout << pFriend.lock()->name << " is " << this->name <<"s friend" << endl;
    }
  }

  void ShowName() const {
    std::cout << name << std::endl;
  }
};



//------------------------------------------Own smart pointer-----------------------------------------------
//template <typename T>
//class smart_ptr
//{
//  T* ptr;
//public:
//  smart_ptr(T* p = nullptr) : ptr(p) {
//
//  }
//  ~smart_ptr() {
//    delete ptr;
//    ptr = nullptr;
//  }
//
//  T& operator*() {
//    return *ptr;
//  }
//  T* operator->() {
//    return ptr;
//  }
//};


//------------------------------------------Own unique pointer-----------------------------------------------

template <class T>
class my_unique_ptr
{
private:
  T * ptr = nullptr;

public:
  my_unique_ptr(T * ptr = nullptr) : ptr(ptr)
  {
    std::cout << __FUNCTION__ << std::endl;
  }

  my_unique_ptr(const my_unique_ptr & obj) = delete; // copy constructor is deleted
  my_unique_ptr& operator=(const my_unique_ptr & obj) = delete; // copy assignment is deleted

  my_unique_ptr(my_unique_ptr && dyingObj) // move constructor
  {
    // Transfer ownership of the memory pointed by dyingObj to this object
    this->ptr = dyingObj.ptr;
    dyingObj.ptr = nullptr;
    std::cout << __FUNCTION__ << std::endl;
  }

  void operator=(my_unique_ptr && dyingObj) // move assignment
  {
    __cleanup__(); // cleanup any existing data

    // Transfer ownership of the memory pointed by dyingObj to this object
    this->ptr = dyingObj.ptr;
    dyingObj.ptr = nullptr;
    std::cout << __FUNCTION__ << std::endl;
  }

  T* operator->() // deferencing arrow operator
  {
    return this->ptr;
  }

  T& operator*()
  {
    return *(this->ptr);
  }

  ~my_unique_ptr() // destructor
  {
    __cleanup__();
    std::cout << __FUNCTION__ << std::endl;
  }

private:
  void __cleanup__()
  {
    if (ptr != nullptr)
      delete ptr;
  }
};


template <class T>
class my_unique_ptr<T[]>
{
private:
  T * ptr = nullptr;

public:
  my_unique_ptr() : ptr(nullptr) // default constructor
  {
  }

  my_unique_ptr(T * ptr) : ptr(ptr)
  {
  }

  my_unique_ptr(const my_unique_ptr & obj) = delete; // copy constructor is deleted
  my_unique_ptr& operator=(const my_unique_ptr & obj) = delete; // copy assignment is deleted

  my_unique_ptr(my_unique_ptr && dyingObj) // move constructor
  {
    __cleanup__(); // cleanup any existing data

    // Transfer ownership of the memory pointed by dyingObj to this object
    this->ptr = dyingObj.ptr;
    dyingObj.ptr = nullptr;
  }

  void operator=(my_unique_ptr && dyingObj) // move assignment
  {
    __cleanup__(); // cleanup any existing data

    // Transfer ownership of the memory pointed by dyingObj to this object
    this->ptr = dyingObj.ptr;
    dyingObj.ptr = nullptr;
  }

  T* operator->() // deferencing arrow operator
  {
    return this->ptr;
  }

  T& operator*()
  {
    return *(this->ptr);
  }

  T& operator[](int index)
  {
    if (index < 0)
    {
      // Throw negative index exception
      throw(new std::exception("Negative index exception"));
    }

    return this->ptr[index]; // doesn't check out of bounds
  }

  ~my_unique_ptr() // destructor
  {
    __cleanup__();
  }

private:
  void __cleanup__()
  {
    if (ptr != nullptr)
      delete[] ptr;
  }
};


template <class T>
class my_shared_ptr
{
  T* ptr;
  int* i;

  void __cleanUp__() {
    (*i)--;
    if (*i == 0) {
      delete ptr;
      delete i;
    }
  }
public:
  my_shared_ptr(T* ptr = nullptr) : ptr(ptr), i(nullptr) {
    i = new int(0);
    (*i)++;
  }

  my_shared_ptr(const my_shared_ptr& sp) {
    ptr = sp.ptr;
    i = sp.i;
    (*i)++;
   
  }

  my_shared_ptr(my_shared_ptr&& sp) {
    __cleanUp__();
    ptr = sp.ptr;
    *i = *(sp.i);
    *i++;
  }

  my_shared_ptr& operator=(my_shared_ptr&& sp) {

    if (this != &sp) {
      __cleanUp__();
      ptr = sp.ptr;
      *i = *(sp.i);
      (*i)++;
    }
    return *this;
  }

  my_shared_ptr& operator=(const my_shared_ptr& sp) {
    if (this != &sp) {
      __cleanUp__();
      ptr = sp.ptr;
      i = sp.i;
      (*i)++;
      
    }
    return *this;
  }

  T& operator*() { return *T; }
  T* operator->() { return T; }

  ~my_shared_ptr() {
    __cleanUp__();
  }
};


int main()
{
  {
    //my_unique_ptr<Dog> up(new Dog("Named1"));

    //my_unique_ptr<Dog> up1 = std::move(up);

    //my_unique_ptr<Dog> up2(new Dog("Named2"));
    //up2 = std::move(up1);
    //up2->ShowName();

    //unique_ptr<Dog[]> up3(new Dog[3]);

    //shared_ptr<Dog[]> sp(new Dog[4], [](Dog* d) { delete[] d; cout << "Custom deleter" << endl; });

    /*my_shared_ptr<Dog> sp1(new Dog("Tommy"));
    {
      my_shared_ptr<Dog> sp2 = sp1;
    }


    my_shared_ptr<Dog> sp3(new Dog);

    sp3 = std::move(sp1);*/

    my_unique_ptr<Dog[]> up(new Dog[3]);

    up[3].ShowName();

    
  }

  {
    //shared_ptr<Dog> sd1(new Dog("Gunner"));
    //  shared_ptr<Dog> sd2(new Dog("Tomy"));
    //  sd1->makefriend(sd2);
    //  //sd2->makefriend(sd1);

    //sd1->ShowFriend();

    //Custom deleter
    //shared_ptr<Dog> d3(new Dog[3], [](Dog* p) {delete[] p; });

    //No need of custom deleted for unique pointer
    std::unique_ptr<Dog> uq(new Dog("Tuffy"));
    std::unique_ptr<Dog[]> ud(new Dog[4]);
  }
}


//print 0-100 without recursion/loop/goto
/*class A
{
  static int a;
public:
  A() {
    cout << ++a << endl;
  }
};

int A::a;

int main()
{
  A a[100];
}*/