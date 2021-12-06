#include "pch.h"
#include "cBinarySearchTree.h"
#include<iostream>


Node* cBinarySearchTree::insertRecursion(Node* node, int iData)
{
  if (node == nullptr)
    return new Node(iData);

  if (iData < node->getData()) {
    node->setLeft(insertRecursion(node->getLeft(), iData));
  }
  else {
    node->setRight(insertRecursion(node->getRight(), iData));
  }
  return node;
}

Node* cBinarySearchTree::FindMin(Node* node)
{
  if (node == nullptr)
    return node;

  while (node->getLeft() != nullptr) {
    node = node->getLeft();
  }
  return node;
}

Node* cBinarySearchTree::DeleteRecursive(Node* node, int iData)
{
  if (node == nullptr)
    return node;

  if (iData < node->getData()) {
    node->setLeft(DeleteRecursive(node->getLeft(), iData));
  }
  else if (iData > node->getData())
  {
    node->setRight(DeleteRecursive(node->getRight(), iData));
  }
  else {
    // Delete leaf node
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
      delete node;
      node = nullptr;
      return node;
    }
    // Delete node having only right child
    else if (node->getLeft() == nullptr) {
      Node* CurrNode = node;
      node = node->getRight();
      delete CurrNode;
      return node;
    }
    // Delete node having only left child
    else if (node->getRight() == nullptr) {
      Node* CurrNode = node;
      node = node->getLeft();
      delete CurrNode;
      return node;
    }
    // delete middle node
    else {
      Node* CurrNode = FindMin(node->getRight());
      node->setData(CurrNode->getData());
      node->setRight(DeleteRecursive(node->getRight(), CurrNode->getData()));
    }
  }
}

void cBinarySearchTree::insertItreative(int iData)
{
  Node* newNode = new Node(iData);
  if (root == nullptr) {
    root = newNode;
    return;
  }

  Node* CurrNode = root;

  while (true) {
    if (newNode->getData() < CurrNode->getData()) {
      if (CurrNode->getLeft() == nullptr) {
        CurrNode->setLeft(newNode);
        break;
      }
      else
        CurrNode = CurrNode->getLeft();
    }
    else {
      if (CurrNode->getRight() == nullptr) {
        CurrNode->setRight(newNode);
        break;
      }
      else
        CurrNode = CurrNode->getRight();
    }
  }
}

void cBinarySearchTree::DeleteInterative(int iData)
{
  if (root == nullptr)
    return;

  Node* CurrNode = root;
  Node* prev = root;
  while (true) {
    if (iData < CurrNode->getData()) {
      prev = CurrNode;
      CurrNode = CurrNode->getLeft();
    }
    else if (iData > CurrNode->getData()) {
      prev = CurrNode;
      CurrNode = CurrNode->getRight();
    }
    else {
      if (CurrNode->getLeft() == nullptr && CurrNode->getRight() == nullptr) {
        if (prev->getLeft() == CurrNode)
          prev->setLeft(nullptr);
        else
          prev->setRight(nullptr);
        delete CurrNode;
        CurrNode = nullptr;
        break;
      }
      else if (CurrNode->getLeft() == nullptr) {
        prev->setRight(CurrNode->getRight());
        delete CurrNode;
        CurrNode = nullptr;
        break;
      }
      else if (CurrNode->getRight() == nullptr) {
        prev->setLeft(CurrNode->getLeft());
        delete CurrNode;
        CurrNode = nullptr;
        break;
      }
      else {
        Node* MinNode = CurrNode->getRight();
        prev = CurrNode;
        while (MinNode->getLeft() != nullptr) {
          prev = MinNode;
          MinNode = MinNode->getLeft();
        }

        if (prev != CurrNode)
          prev->setLeft(MinNode->getRight());
        else
          prev->setRight(MinNode->getRight());

        CurrNode->setData(MinNode->getData());
        delete MinNode;
        MinNode = nullptr;
        break;
      }
    }
  }
}

void cBinarySearchTree::InOrder(Node* node)
{
  if (node == nullptr)
    return;

  InOrder(node->getLeft());
  std::cout << " " << node->getData();
  InOrder(node->getRight());
}

cBinarySearchTree::~cBinarySearchTree()
{
}
