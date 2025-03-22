// LinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SinglyLinkList.cpp"

int main()
{
    SinglyLinkList<int> sl;
    sl.push_back(10);

    sl.reverse();

    std::cout << sl;

    sl.push_back(20);
    sl.push_back(30);
    sl.push_back(40);
    sl.push_back(50);
    sl.insert(60,10);
    sl.insert(25, 3);

    std::cout << sl;

    sl.reverse_recursion();

    std::cout << sl;

    sl.clear();
}
