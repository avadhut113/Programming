// stack_link_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node{
  node* prev;
  int data;
  node(int d) {
    prev = nullptr;
    data = d;
  }
};

class stack
{
  node* head = nullptr;
public:
  stack(){}
  void push(int data);
  int pop();
  void display();
  ~stack() {}
};

void stack::push(int data)
{
  node* newnode = new node(data);
  if (head == nullptr)
    head = newnode;
  else {
    newnode->prev = head;
    head = newnode;
  }
}

int stack::pop()
{
  if (head == nullptr) {
    std::cout << "stack under flow" << std::endl;
    return 0;
  }
  else {
    int poped = head->data;
    node* temp = head;
    head = head->prev;
    delete temp;
    return poped;
  }
}

void stack::display()
{
  if (head == nullptr) {
    std::cout << "stack empty" << std::endl;
  }
  else {
    node* temp = head;
    while (temp)
    {
      std::cout << temp->data << std::endl;
      temp = temp->prev;
    }
  }
}

int main()
{
  stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << "Poped : " << s.pop() << std::endl;
  s.push(4);
  s.push(5);
  std::cout << "Poped : " << s.pop() << std::endl;
  s.push(6);
  s.push(7);
  s.display();

}

