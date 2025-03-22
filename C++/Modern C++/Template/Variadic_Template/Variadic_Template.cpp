// Variadic_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <memory.h>


class String
{
  char * str;
  int size;

  friend std::istream& operator>>(std::istream& is, String& s) {
    return is >> s.str;
  }

  friend std::ostream& operator<<(std::ostream& os, String&s) {
    return os << s.str;
  }
public:
  String() : size(0), str(nullptr) {
    std::cout << "Default Ctor" << std::endl;
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
    std::cout << "Paramet Ctor" << std::endl;
  }

  String(const String& s) : size(s.size) {
    str = new char[size + 1];
    strcpy(str, s.str);

    std::cout << "Copy Ctor" << std::endl;
  }

  String(String&& s) : size(s.size), str(s.str) {
    s.size = 0;
    s.str = nullptr;
    std::cout << "Move Ctor" << std::endl;
  }

  String& operator=(String&& s) {
    if (this != &s) {
      size = s.size;
      str = s.str;
      s.size = 0;
      s.str = nullptr;
    }
    std::cout << "Move Assign" << std::endl;
    return *this;
  }

  String& operator=(const String& s) {
    if (this == &s)
      return *this;

    delete str;
    size = s.size;
    str = new char[size + 1];
    strcpy(str, s.str);
    std::cout << "Copy Assign" << std::endl;
    return *this;
  }

  void* operator new(size_t s) {
    while (true) {
      void* mem = malloc(s);
      if (mem)
        return mem;

      std::new_handler nh = std::set_new_handler(0);
      std::set_new_handler(nh);

      if (nh)
        (*nh)();
      else
        throw std::bad_alloc();
    }
    std::cout << __FUNCTION__ << std::endl;
  }

  void operator delete(void* v) {
    if (v)
      free(v);
    std::cout << __FUNCTION__ << std::endl;
  }

  int length() const {
    return size;
  }

  String& operator+(const String& s2) {
    size = this->size + s2.size;
    char* temStr = str;
    str = new char[size + 1];
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



//Base function to end recursion loop
void print()
{
}

template<typename T,typename...Params>
void print(T&& a,Params&&...args)
{
  /*std::cout << sizeof...(Params);
  std::cout << sizeof...(args) << std::endl;*/
  std::cout << typeid(a).name() << " : " << a << std::endl;
  print(std::forward<Params>(args)...);
}

int main()
{
  print(1, 2.5, String{"Test"});
}

