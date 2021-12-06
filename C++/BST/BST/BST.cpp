// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cBinarySearchTree.h"

int main()
{
    cBinarySearchTree bst;
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 50));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 30));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 20));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 40));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 70));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 60));
    bst.setRoot(bst.insertRecursion(bst.getRoot(), 80));

    bst.InOrder(bst.getRoot());
    bst.DeleteRecursive(bst.getRoot(), 50);
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
