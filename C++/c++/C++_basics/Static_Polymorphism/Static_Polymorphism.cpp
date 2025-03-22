// Static_Polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;

class String
{
  char * str;
  int size;

  friend istream& operator>>(istream& is, String& s) {
    return is >> s.str;
  }

  friend ostream& operator<<(ostream& os, String&s) {
    return os << s.str;
  }
public:
  String() : size(0), str(nullptr) {
  }

  explicit String(const char* s) : size(strlen(s)) {
    if (s == nullptr) {
      str = new char[1];
      str[0] = '\0';
    }
    else {
      str = new char[size + 1];
      strcpy(str, s);
    }
  }

  String(const String& s) : size(s.size) {
    str = new char[size+1];
    strcpy(str, s.str);
  }

  String(String&& s) : size(s.size), str(s.str) {
    s.size = 0;
    s.str = nullptr;
  }

  String& operator=(const String&& s) {
    size = s.size;
    str = s.str;
  }

  String& operator=(const String& s) {
    if (this == &s)
      return *this;

    delete str;
    size = s.size;
    str = new char[size+1];
    strcpy(str, s.str);
    return *this;
  }

  void* operator new(size_t s) {
    while (true) {
      void* mem = malloc(s);
      if (mem)
        return mem;

      new_handler nh = set_new_handler(0);
      set_new_handler(nh);

      if (nh)
        (*nh)();
      else
        throw bad_alloc();
    }
  }

  void operator delete(void* v) {
    if (v)
      free(v);
  }

  int length() const {
    return size;
  }

  String& operator+(const String& s2) {
    size = this->size + s2.size;
    char* temStr = str;
    str = new char[size+1];
    strcpy(str, temStr);
    delete temStr;
    strcat(str, s2.str);
    return *this;
  }

  String& operator+=(const String& s) {
    *this = *this + s;
    return *this;
  }

  bool operator==(const String& s) {
    if (*this == s)
      return true;

    return false;
  }

  friend String operator+(const String& s1, const String& s2);

  ~String() {
    delete str;
    size = 0;
  }

};

String operator+(const String& s1, const String& s2) {
  int size = s1.size + s2.size;

  char* buff = new char[size + 1];
  strcpy(buff, s1.str);
  strcat(buff, s2.str);

  String temp{ buff };
  delete[] buff;
  return temp;
}

template<class T>
class smart_ptr
{
  T* ptr;
public:
  smart_ptr(T* p)
  {
    ptr = p;
  }
  ~smart_ptr() {
    delete ptr;
  }
  T* operator->() {
    return ptr;
  }
  T& operator*() {
    return *ptr;
  }
};


int main()
{
  String s1("abc");
  String s2(s1);
  String s3;
  s1 += s2;
  s3 = s1 + s2;

  double d = fmod(40.1, 5);

  {
    smart_ptr<String> i(new String("ijk"));
    std::cout << *i << std::endl;
    std::cout << i->length() << std::endl;
  }

}
