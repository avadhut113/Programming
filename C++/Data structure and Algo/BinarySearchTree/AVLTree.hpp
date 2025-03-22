#pragma once
#include "Node.hpp"
#include <iostream>
#include <initializer_list>

template<typename T>
class AVLTree
{
	Node<T>* m_root{ nullptr };
	int Height(Node<T>* node);
	int getBalanceFactor(Node<T>* node);
	Node<T>* rightRotate(Node<T>* y);
	Node<T>* leftRotate(Node<T>* y);
	Node<T>* InsertRecursion(T i, Node<T>* p);
	Node<T>* DeleteRecursive(Node<T>* node, T data);

	Node<T>* SearchRecursion(T data, Node<T>* curr);
	Node<T>* Inordersuccessor(Node<T>* node)
	{
		while (node && node->left)
			node = node->left;

		return node;
	}
	Node<T>* InorderPredecessor(Node<T>* node)
	{
		while (node && node->right)
			node = node->right;

		return node;
	}

	void InOrderTraversal(Node<T>* node)
	{
		if (node) {
			InOrderTraversal(node->left);
			std::cout << node->data << " ";
			InOrderTraversal(node->right);
		}
	}
	void PreOrderTraversal(Node<T>* node)
	{
		if (node) {
			std::cout << node->data << " ";
			PreOrderTraversal(node->left);
			PreOrderTraversal(node->right);
		}
	}
	void PostOrderTraversal(Node<T>* node)
	{
		if (node) {
			PostOrderTraversal(node->left);
			PostOrderTraversal(node->right);
			std::cout << node->data << " ";
		}
	}

	int countRecursive(Node<T>* root)
	{
		int x, y;
		if (root) {
			x = countRecursive(root->left);
			y = countRecursive(root->right);
			return x + y + 1;
		}
		return 0;
	}
	int heightRecursive(Node<T>* root)
	{
		int x, y;
		if (root) {
			x = heightRecursive(root->left);
			y = heightRecursive(root->right);
			return x > y ? x + 1 : y + 1;
		}
		return 0;
	}
public:

	AVLTree() = default;
	AVLTree(std::initializer_list<T> list)
	{
		for (const auto item : list) {
			InsertRecursion(item);
		}
	}

	~AVLTree() = default;
	Node<T>* SearchRecursion(T data);
	void InsertRecursion(T i);
	void DeleteRecursive(T data);

	//Tree Traversal Recursive
	void InOrderTraversal() { InOrderTraversal(m_root); std::cout << std::endl; }
	void PreOrderTraversal() { PreOrderTraversal(m_root); std::cout << std::endl; }
	void PostOrderTraversal() { PostOrderTraversal(m_root); std::cout << std::endl; }
};

template<typename T>
Node<T>* AVLTree<T>::SearchRecursion(T data, Node<T>* curr)
{
	if (curr->data == data)
		return curr;

	if (data < curr->data)
		SearchRecursion(data, curr->left);
	else
		SearchRecursion(data, curr->right);

	return nullptr;
}

template<typename T>
Node<T>* AVLTree<T>::SearchRecursion(T data)
{
	return SearchRecursion(data, m_root);
}

template<typename T>
inline int AVLTree<T>::Height(Node<T>* node)
{
	int hr{ 0 }, hl{ 0 };
	if (node && node->left)
		hl = node->left->height;
	if (node && node->right)
		hr = node->right->height;

	return hl > hr ? hl + 1 : hr + 1;
}

template<typename T>
inline int AVLTree<T>::getBalanceFactor(Node<T>* node)
{
	int hr{ 0 }, hl{ 0 };
	if (node && node->left)
		hl = node->left->height;
	if (node && node->right)
		hr = node->right->height;

	return hl - hr;
}

// Rotate right
template<typename T>
Node<T>* AVLTree<T>::rightRotate(Node<T>* y) {
	Node<T>* x = y->left;
	Node<T>* T2 = x->right;
	x->right = y;
	x->parent = y->parent;
	y->parent = x;
	y->left = T2;
	if(T2)
		T2->parent = y;
	y->height = Height(y);
	x->height = Height(x);
	return x;
}

// Rotate left
template<typename T>
Node<T>* AVLTree<T>::leftRotate(Node<T>* x) {
	Node<T>* y = x->right;
	Node<T>* T2 = y->left;
	y->left = x;
	y->parent = x->parent;
	x->parent = y;
	x->right = T2;
	if(T2)
		T2->parent = x;
	x->height = Height(x);
	y->height = Height(y);
	return y;
}

template<typename T>
Node<T>* AVLTree<T>::InsertRecursion(T data, Node<T>* node)
{
	if (!node)
		return new Node<T>(data);

	else if (data < node->data) {
		node->left = InsertRecursion(data, node->left);
		node->left->parent = node;
	}
	else if (data > node->data) {
		node->right = InsertRecursion(data, node->right);
		node->right->parent = node;
	}
	else
		return node;

	node->height = Height(node);
	int balancefactor = getBalanceFactor(node);

	if (balancefactor > 1) {
		if (data < node->left->data) {
			return rightRotate(node);
		}
		else if (data > node->left->data) {
			node->left = leftRotate(node->left);
			node->left->parent = node;
			return rightRotate(node);
		}
	}
	if (balancefactor < -1) {
		if (data > node->right->data) {
			return leftRotate(node);
		}
		else if (data < node->right->data) {
			node->right = rightRotate(node->right);
			node->right->parent = node;
			return leftRotate(node);
		}
	}
	return node;
}

template<typename T>
void AVLTree<T>::InsertRecursion(T i)
{
	m_root = InsertRecursion(i, m_root);
}

template<typename T>
Node<T>* AVLTree<T>::DeleteRecursive(Node<T>* node, T data)
{
	if (nullptr == node) {
		std::cout << "Data is not present" << std::endl;
		return nullptr;
	}

	if (data == node->data && nullptr == node->left && nullptr == node->right) {
		delete node;
		return nullptr;
	}

	if (data < node->data) {
		node->left = DeleteRecursive(node->left, data);
		/*if(node->left)
			node->left->parent = node;*/
	}
	else if (data > node->data) {
		node->right = DeleteRecursive(node->right, data);
		/*if(node->right)
			node->right->parent = node;*/
	}
	else {
		if (heightRecursive(node->left) > heightRecursive(node->right)) {
			Node<T>* pred = InorderPredecessor(node->left);
			node->data = pred->data;
			node->left = DeleteRecursive(node->left, pred->data);
			/*if (node->left)
				node->left->parent = node;*/
		}
		else {
			Node<T>* succe = Inordersuccessor(node->right);
			node->data = succe->data;
			node->right = DeleteRecursive(node->right, succe->data);
			/*if (node->right)
				node->right->parent = node;*/
		}
	}

	// Update the balance factor of each node and
	// balance the tree
	node->height = Height(node);
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (getBalanceFactor(node->left) >= 0) {
			return rightRotate(node);
		}
		else {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (getBalanceFactor(node->right) <= 0) {
			return leftRotate(node);
		}
		else {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

template<typename T>
void AVLTree<T>::DeleteRecursive(T i)
{
	m_root = DeleteRecursive(m_root, i);
}


