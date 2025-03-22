#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include "Node.hpp"

template<typename T>
class Tree
{
    Node<T>* root;
    Node<T>* insert_at_sub(T i, Node<T>*);
    Node<T>* delete_at_sub(T i, Node<T>*);
    int countNodes(Node<T>* p);
    void print_sub(Node<T>* p);
    Node<T>* minValue(Node<T>*);
    Node<T>* maxValue(Node<T>*);
    Node<T>* get_last(Node<T>*);
    Node<T>* get_first(Node<T>*);
    int t_size = 0;

public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree()
    {
        delete root;
    }

    void add(T i)
    {
        ++t_size;

        root = insert_at_sub(i, root);
    }
    void print()
    {
        print_sub(root);
    };

    bool contain(T i)
    {
        return contain_sub(i, root);
    }
    bool contain_sub(T i, Node<T>* p);

    void destroy(T i)
    {
        if (contain(i))
            root = delete_at_sub(i, root);
        else
            return;
    }

    void showFirst();
    void showLast();

    int get_size()
    {
        return t_size;
    }

    int getNumberLeftNodes()
    {
        return countNodes(root->left);
    }

    int getNumberRightNodes()
    {
        return countNodes(root->right);
    }
};

template<typename T>
int  Tree<T>::countNodes(Node<T>* p)
{
    static int nodes;

    if (!p)
        return 0;
    if (p->left)
    {
        ++nodes;
        countNodes(p->left);
    }
    if (p->right)
    {
        ++nodes;
        countNodes(p->right);
    }

    return nodes + 1;
}

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T>* p)
{
    if (!p)
        return new Node<T>(i);
    else if (i <= p->data)
        p->left = insert_at_sub(i, p->left);
    else if (i > p->data)
        p->right = insert_at_sub(i, p->right);

    return p;
}

template<typename T>
void Tree<T>::print_sub(Node<T>* p)
{
    if (p)
    {
        print_sub(p->left);
        std::cout << p->data << std::endl;
        print_sub(p->right);
    }
}

template<typename T>
bool Tree<T>::contain_sub(T i, Node<T>* p)
{
    if (!p)
        return false;
    else if (i == p->data)
        return true;
    else if (i <= p->data)
        contain_sub(i, p->left);
    else
        contain_sub(i, p->right);
}

template<typename T>

Node<T>* Tree<T>::minValue(Node<T>* p)
{
    Node<T>* current = p;

    while (current && current->left)
        current = current->left;

    return current;
}

template<typename T>
Node<T>* Tree<T>::maxValue(Node<T>* p)
{
    Node<T>* current = p;

    while (current && current->right)
        current = current->right;

    return current;
}

template<typename T>
void Tree<T>::showLast()
{
    Node<T>* last = maxValue(root);

    if (last)
        std::cout << last->data;
    else
        std::cout << "";
}

template<typename T>
void Tree<T>::showFirst()
{
    Node<T>* first = minValue(root);

    if (first)
        std::cout << first->data;
    else
        std::cout << "";
}


template<typename T>
Node<T>* Tree<T>::delete_at_sub(T i, Node<T>* p)
{
    if (i < p->data)
        p->left = delete_at_sub(i, p->left);
    else if (i > p->data)
        p->right = delete_at_sub(i, p->right);
    else if (i == p->data)
    {
        if (!p->left)
        {
            Node<T>* temp = p->right;
            delete p;

            return temp;
        }
        else if (!p->right)
        {
            Node<T>* temp = p->left;
            delete p;

            return temp;
        }

        Node<T>* temp = minValue(p->right);

        p->data = temp->data;

        p->right = delete_at_sub(p->data, p->right);
    }

    return p;
}

#endif // TREE_H_INCLUDED
