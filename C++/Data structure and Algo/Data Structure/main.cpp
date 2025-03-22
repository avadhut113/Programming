// Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinarySearchTree.hpp"
#include <iostream>
#include <thread>

void testBST()
{
    CBinarySearchTree<int> bst;
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(70);
    bst.Insert(60);
    bst.Insert(80);
    bst.bfs();

    bst.Delete(30);
    bst.Delete(40);
    bst.InOrder();
}

int main()
{
    testBST();

    //std::cout << std::thread::hardware_concurrency();
}

