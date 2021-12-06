// Type_Cating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>

class dog
{
public :
  std::string name;
  explicit dog(std::string s) : name(s) {}
  virtual void bark() {
    std::cout << "Dog " << name << " Bark" << std::endl;
  }
};

class yellowdog : public dog
{
public:
  std::string prop;
  explicit yellowdog(std::string s) : dog(s) {}
  void bark() {
    std::cout << "yellow dog "<< name <<" bark " << std::endl;
  }
};


void getlongseq(int arr[], int size)
{
  int iStart = 0, count = 0, iEnd = 0;
  int i = 0, j = 0;

  while (j < size) {
    if (i == j) {
      j++;
    }
    else {
      if (arr[j - 1] < arr[j]) {
        j++;
      }
      else {
        if (j - i > count)
        {
          iStart = i;
          iEnd = j - 1;
          count = j - i;
          i = j;
        }
      }
    }
  }

  if (j - i > count)
  {
    iStart = i;
    iEnd = j - 1;
    count = j - i;
  }

  for (int k = iStart; k <= iEnd; k++)
    std::cout << arr[k] << std::endl;
}

int main()
{

  //-------------------static_cast------------------
  //convert object from one type to aother
  double x = 5;
  //
  //double& i = static_cast<double&>(x);
  //std::cout << i << std::endl;

  //static_cast use explicit constructor
  //convert ponter/reference to related type
  //dog s1 = std::string("abc");
  dog s = static_cast<dog>(std::string("hello"));
  s.bark();

  dog* d = dynamic_cast<dog*>(new yellowdog("Motu"));
  d->bark();

  //Should be polymorphic type
  yellowdog* yd = dynamic_cast<yellowdog*>(new dog("Chotu"));
  if (yd)
    yd->bark();

  const yellowdog* yd1 = new yellowdog("Const chotu");
  yellowdog* yd2 = const_cast<yellowdog*>(yd1);
  yd2->bark();

  //int* p = reinterpret_cast<int*>('a');
  //std::cout << *p << std::endl;

  int arr[] = { 8,9,1,2,3,4,11,12,14,4,19,39,51,64 };
  int size = 14;

  getlongseq(arr, size);


}