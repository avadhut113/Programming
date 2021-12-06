// Lambda_Exp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


template <typename T, int size, typename comparator>
void sort(T(&arr)[size], comparator comp)
{
  for (int i = 0; i < size ; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (comp(arr[j] , arr[j + 1])) {
        T temp = std::move(arr[j]);
        arr[j] = std::move(arr[j + 1]);
        arr[j + 1] = std::move(temp);
      }
    }
  }
}

struct functor
{
  int state;
  int i;
  functor() : state(0) {}
  functor(int s) : state(s) {}
  void operator()() {

  }
};



// A function to print all combination of a given length from the given array.
void Combination(int a[], int reqLen, int start, int currLen, bool check[], int len)
{
  // Return if the currLen is more than the required length.
  if (currLen > reqLen)
    return;
  // If currLen is equal to required length then print the sequence.
  else if (currLen == reqLen)
  {
    cout << "\t";
    for (int i = 0; i < len; i++)
    {
      if (check[i] == true)
      {
        cout << a[i] << " ";
      }
    }
    cout << "\n";
    return;
  }
  // If start equals to len then return since no further element left.
  if (start == len)
  {
    return;
  }
  // For every index we have two options.
  // First is, we select it, means put true in check[] and increment currLen and start.
  check[start] = true;
  Combination(a, reqLen, start + 1, currLen + 1, check, len);
  // Second is, we don't select it, means put false in check[] and only start incremented.
  check[start] = false;
  Combination(a, reqLen, start + 1, currLen, check, len);
}

//int main()
//{
//  int i, n;
//  cout << "Enter the number of element array have: ";
//  cin >> n;
//
//  bool check[10];
//
//  int arr[10];
//  cout << "\n";
//
//  // Take the input of the array.
//  for (i = 0; i < n; i++)
//  {
//    cout << "Enter " << i + 1 << " element: ";
//    cin >> arr[i];
//    check[i] = false;
//  }
//  
//
//  // For each length of sub-array, call the Combination().
//  for (i = 1; i <= n; i++)
//  {
//    cout << "\nThe combination of  length " << i << " for the given array set:\n";
//    Combination(arr, i, 0, 0, check, 10);
//  }
//  return 0;
//}


template<typename T, int size, typename callable>
void foreach(T (&arr)[size], callable call) {
  for (int i = 0; i < size; i++)
  {
    call(arr[i]);
  }
}

template<typename T,int size>
void PrintArraySize(T(&arr)[size]) {
  std::cout << size << std::endl;
}

int main()
{
  int list[] = { 1,2,3,4,5 };
  PrintArraySize(list);
  int optr = 5;
  int sum{};
  foreach(list, [&sum](int &x)mutable { 
    sum += x ; 
    
  });

  for (auto i : list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << sum << std::endl;

  int arr[] = {12 ,1 ,5 ,11 , 89, 2};
  sort(arr, [](int x, int y) {return x < y; });

  for (auto i : arr) {
    std::cout << i << " ";
  }

  atexit([]() {cout << "Lambda at exit"; });

  []() {
    cout << "Direct lambda expression" << endl;
  }();

  auto fun = []() {
    cout << "stored lambda expression"<<endl;
  };
  fun();

  auto lamda = [](auto x, auto y) {
    return x + y;
  };

  double d = lamda(5.6, 6);

  int x = 1;
  vector<int> vect{1,2,3,4,5};
  cout << [x](auto a) mutable -> int { x += a; return x; }(5) << endl;
  cout << "x :" << x << endl;




}