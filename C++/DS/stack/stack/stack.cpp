// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX_SIZE 5

template<class T>
class stack
{
  int top = -1;
  T arr[MAX_SIZE];
public:
  void push(T item) {
    if (top < MAX_SIZE - 1) {
      top++;
      arr[top] = item;
    }
    else {
      std::cout << "stack overflow" << std::endl;
      return;
    }
  }
  void pop() {
    if (top > -1) {
      std::cout << "Item poped out = " << arr[top] << std::endl;
      top--;
    }
    else {
      std::cout << "stack underflow" << std::endl;
      return;
    }
  }
  void display() {
    for (int i = top; i > -1; i--)
      std::cout << " " << arr[i];

    std::cout << " " << std::endl;
  }
  
};

int main()
{
  stack<int> st;
  st.push(5);
  st.push(4);
  st.push(3);
  st.push(2);
  st.push(1);
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();


  st.display();

}

