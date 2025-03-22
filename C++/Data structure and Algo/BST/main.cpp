// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cBinarySearchTree.h"

int main()
{
    cBinarySearchTree bst;
    bst.insertRecursion(50);
    bst.insertRecursion(30);
    bst.insertRecursion(20);
    bst.insertRecursion(40);
    bst.insertRecursion(70);
    bst.insertRecursion(60);
    bst.insertRecursion(80);

    bst.InOrder(bst.getRoot());
    bst.DeleteRecursive(50);
    std::cout << " " << std::endl;
    bst.InOrder(bst.getRoot());

    cBinarySearchTree bst2;
    bst2.insertItreative(50);
    bst2.insertItreative(30);
    bst2.insertItreative(70);
    bst2.insertItreative(20);
    bst2.insertItreative(40);
    bst2.insertItreative(60);
    bst2.insertItreative(80);
    bst2.insertItreative(90);
    bst2.insertItreative(55);
    bst2.insertItreative(53);
    bst2.insertItreative(57);

    std::cout << " " << std::endl;
    bst2.InOrder(bst2.getRoot());
    bst2.DeleteInterative(57);
    std::cout << " " << std::endl;
    bst2.InOrder(bst2.getRoot());
}
