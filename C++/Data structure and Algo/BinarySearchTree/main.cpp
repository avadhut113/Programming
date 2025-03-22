// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"

void BST_Test()
{
    CBinarySearchTree<int> BST{ 10,5,3,2,1,4,7,6,9,8,15,13,12,11,14,17,16,19,18 };

    //BST.InsertIterative(5);
    //BST.InsertIterative(3);
    //BST.InsertIterative(2);
    //BST.InsertIterative(4);
    //BST.InsertRecursion(8);
    //BST.InsertRecursion(6);
    //BST.InsertRecursion(9);
    //BST.InsertRecursion(10);

    Node<int>* key = BST.SearchRecursion(9);
    std::cout << "\n\n InOrder" << std::endl;
    BST.InOrderTraversal();
    BST.inOrderIterative();

    std::cout << "\n\n PreOrder" << std::endl;
    BST.PreOrderTraversal();
    BST.PreOrderIterative();

    std::cout << "\n\n PostOrder" << std::endl;
    BST.PostOrderTraversal();
    BST.PostOrderIterative();

    std::cout << "\n\n Level Order" << std::endl;
    BST.levelOrderTraversal();

    std::cout << "\n\n Count : " << std::endl;
    std::cout << BST.countIterative() << std::endl;
    std::cout << BST.countRecursive() << std::endl;

    std::cout << "\n\n Height : " << std::endl;
    std::cout << BST.heightIterative() << std::endl;
    std::cout << BST.heightRecursive() << std::endl;


    std::cout << "\n\n Delete Node : " << std::endl;
    // BST.DeleteRecursive(8);
    BST.DeleteIterative(5);
    BST.DeleteIterative(15);
    BST.inOrderIterative();

    BST.DeleteRecursive(10);
    BST.DeleteRecursive(14);
    BST.inOrderIterative();
}

void avl_test()
{
    AVLTree<int> BST{ 10,5,3,2,1,4,7,6,9,8,15,13,12,11,14,17,16,19,18 };

    BST.DeleteRecursive(7);
    BST.DeleteRecursive(8); 
    BST.DeleteRecursive(1);
    BST.DeleteRecursive(2);
    std::cout << "\n\n InOrder" << std::endl;
    BST.InOrderTraversal();
}

int main()
{
    //BST_Test();
    avl_test();
}

