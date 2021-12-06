#include <iostream>
#include <fstream>
#include <vector>
//Old Code
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//float Max(float x, float y) {
//	return x > y ? x : y;
//}

//Primary Template
template<typename T>
T Max(T x, T y) {
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}
//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> const char * Max<const char*>(const char *x, const char *y) {
	std::cout << "Max<const char*>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

void Examples() {
#pragma region Instantiation Examples
	Max(static_cast<float>(3), 5.5f);

	//Override compiler's deduction process
	Max<double>(3, 6.2);

	//Causes implicit instantiation of Max<int>
	int(*pfn)(int, int) = Max;

#pragma endregion
#pragma region Explicit Instantiation
	const char *b{ "B" };
	const char *a{ "A" };
	auto s = Max(a, b);
	std::cout << s << std::endl;
#pragma endregion
}

//Non-type template parameter
template<int size>
void Print() {
	char buffer[size];
	std::cout << size << std::endl;
}
//Requires size as explicit argument
template<typename T>
T Sum(T*parr, int size){
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
//Size is implicitly calculated in non-type template argument
template<typename T,int size>
T Sum(T (&arr)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}


class Demo
{
  int* i;
  const int ci;
  static int si;
public:
  int var = 0;
  Demo() : ci(0) {
    i = new int(0);
  }
  explicit Demo(int* ptr, int con) : ci(con) {
    i = new int(*ptr);
  }
  Demo(const Demo& d) : ci(d.ci) {
    
     i = new int(*(d.i));
  }
  Demo& operator=(const Demo &d) {
    if (this != &d) {
      *i = *(d.i);
      *const_cast<int*>(&ci) = d.ci;
    }


    return *this;
  }

  bool fun() {
    std::cout << "fun" << var << std::endl;
    return true;
  }

  Demo(Demo&& d) : ci(d.ci) {
    i = d.i;
    d.i = nullptr;
  }
  Demo& operator=(Demo &&d) {
    if (this != &d) {
      i = d.i;
      d.i = nullptr;
    }

    return *this;
  }
  ~Demo() {
    if (i != nullptr)
      delete i;
  }
};

int Demo::si = 0;



class String
{
  friend std::ostream& operator<<(std::ostream& ofs, const String& s);
  friend std::ifstream& operator>>(std::ifstream& ifs, String& s);
  char* str;

  void __clean__() {
    if (str) {
      delete[] str;
      str = nullptr;
    }
  }

public:
  String() : str(nullptr) {
    str = new char[1];
    str = '\0';
    std::cout << "Default constructor" << std::endl;
  }
  String(char* ptr) {
    if (ptr) {
      str = new char[strlen(ptr) + 1];
      strcpy(str, ptr);
    }
    else {
      str = new char[1];
      str = '\0';
    }
    std::cout << "parameterized constructor" << std::endl;
  }

  String(const String& s) {
    if (s.str) {
      str = new char[strlen(s.str) + 1];
      strcpy(str, s.str);
    }
    else {
      str = new char[1];
      str = '\0';
    }
    std::cout << "copy constructor" << std::endl;
  }
  String& operator=(String& s) {
    if (this != &s) {
      __clean__();

      str = new char[strlen(s.str) + 1];
      strcpy(str, s.str);
    }
    return *this;
  }

  String(String&& s) {
    str = s.str;
    s.str = nullptr;
    std::cout << "move constructor" << std::endl;
  }
  String& operator=(String&& s) {
    if (this != &s) {
      __clean__();
      str = s.str;
      s.str = nullptr;
    }
    return *this;
  }

  ~String() {
    __clean__();
    std::cout << "destructor" << std::endl;
  }
};

std::ostream& operator<<(std::ostream& ofs, const String& s) {
  if (&s && s.str)
    ofs << s.str;
  else
    ofs << "empty String";
  return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, String& s) {
  char* ptr = new char[1000];
  ifs >> ptr;
  s = String{ ptr };
  delete[] ptr;
  return ifs;
}


template<class T>
class my_shared_ptr
{
  T* ptr;
  unsigned int* count;

  void __clean__() {
    if (count != nullptr) {
      (*count)--;
      if (*count == 0)
      {
        if (nullptr != ptr)
          delete ptr;
        delete count;
      }
    }
  }
public:
  my_shared_ptr() :ptr(nullptr), count(new int(0)) {

  }

  explicit my_shared_ptr(T* p) : ptr(p) {
    count = new unsigned int(0);
    (*count)++;
  }

  my_shared_ptr(const my_shared_ptr& sp) {
    ptr = sp.ptr;
    count = sp.count;
    (*count)++;
  }

  my_shared_ptr& operator=(const my_shared_ptr& sp) {
    if (this != &sp) {
      __clean__();
      ptr = sp.ptr;
      count = sp.count;
      (*count)++;
    }
    return *this;
  }

  my_shared_ptr(my_shared_ptr&& sp) {
    ptr = sp.ptr;
    count = sp.count;

    sp.ptr = nullptr;
    sp.count = nullptr;
  }

  my_shared_ptr& operator=(my_shared_ptr&& sp) {
    if (this != &sp) {
      __clean__();

      ptr = sp.ptr;
      count = sp.count;

      sp.ptr = sp.count = nullptr;

    }
  }

  T* get() {
    return ptr;
  }

  T* operator->() {
    return ptr;
  }

  T& operator*() {
    return *ptr;
  }

  unsigned int get_count() const {
    return *count;
  }

  ~my_shared_ptr() {
    __clean__();
  }
};


void funfoo(String s) {

}

int main() {

  std::cout<<Max(5, 6)<<std::endl;

  Demo* d = nullptr;
  if (d && d->fun())
    std::cout << d->var << std::endl;

  String s;
  String s1{ "abc" };
  s = s;
  funfoo(std::move(String("pqr")));
  s = s1;
  std::cout << s << std::endl;


  my_shared_ptr<String> sp1(new String("abc"));
  my_shared_ptr<String> sp2 = sp1;
  std::cout << *sp2 << std::endl;

  my_shared_ptr<String> sp3(new String("xyz"));
  sp2 = sp3;
  std::cout << *sp2 << std::endl;

  my_shared_ptr<String> sp4 = std::move(sp2);
  std::cout << *sp2 << std::endl;
  std::cout << *sp4 << std::endl;


 // int i = 23;
 // Demo d;
 // Demo d1 = d;
 // Demo d2(&i, 45);
	//Print<3>();
	//int arr[]{ 3,1,9,7 };
	//int (&ref)[4] = arr ;
	//int sum = Sum(arr);
	//std::cout << sum << std::endl; 
	return 0;
}