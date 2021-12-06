#pragma once

struct Node
{
  int data;
  Node *left, *right;

  Node(int data) {
    this->data = data;
    left = right = nullptr;
  }

  void setData(int iData) { data = iData; }
  int getData() { return data; }
  void setLeft(Node* left) { this->left = left; }
  Node* getLeft() { return this->left; }
  void setRight(Node* right) { this->right = right; }
  Node* getRight() { return this->right; }
};

class cBinarySearchTree
{
  Node* root;
public:
  cBinarySearchTree() { root = nullptr; }
  Node* getRoot() { return this->root; }
  void setRoot(Node* root) { this->root = root; }

  Node* FindMin(Node* node);

  Node* insertRecursion(Node* node, int iData);
  Node* DeleteRecursive(Node* node, int iData);

  void insertItreative(int iData);
  void DeleteInterative(int iData);

  void InOrder(Node* node);
  virtual ~cBinarySearchTree();
};

