// excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node* left{ nullptr }, * right{ nullptr }, * parent{ nullptr };

    Node(T value) : value(value) {}

    Node(T value, Node<T>* left, Node<T>* right) : value(value), left(left), right(right) {
        left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder(Node<T>* node, vector<Node<T>*>& result)
    {
        if (node == NULL)
            return;

        result.push_back(node);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    void preorder_traversal(vector<Node<T>*>& result)
    {
        preorder(this, result);
    }
};

int main()
{
    Node<char> a{ 'a' }, b{ 'b' }, c{ 'c' };
    a.left = &b;
    a.right = &c;

    vector<Node<char>*> result;
    a.preorder_traversal(result);

}
