// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};

void reverse(Node* head) {
  Node* temp = head;

  while (temp->next != nullptr) {
    Node* temp2 = temp->next;
    temp->next = temp->prev;
    temp->prev = temp2;
    temp = temp2;
   }
  head = temp;
}

int main()
{
    std::cout << "Hello World!\n";
}

