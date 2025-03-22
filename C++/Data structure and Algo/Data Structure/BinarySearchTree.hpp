#pragma once
#include <print>
#include <iostream>
#include <deque>


template <class T>
struct Node {
	T data;
	Node* left{ nullptr };
	Node* right{ nullptr };
	Node* parent{ nullptr };
};

template <class T>
class CBinarySearchTree
{
public:
	CBinarySearchTree() = default;
	
	void Insert(T data) { 
		m_Root = Insert(m_Root, data); 
	}

	
	void InOrder() { InOrder(m_Root);  std::cout << "\n";}
	void PreOrder() { PreOrder(m_Root);  std::cout << "\n"; }
	void PostOrder() { PostOrder(m_Root);  std::cout << "\n"; }
	void bfs() {
		if (!m_Root)
			return;

		std::deque<decltype(m_Root)> q;
		q.push_back(m_Root);

		while (!q.empty()) {
			auto node = q.front(); q.pop_front();

			if (node->left) q.push_back(node->left);
			if (node->right) q.push_back(node->right);

			std::cout << node->data << " ";
		}
		std::cout << "\n";
	}

	void Clear() { m_Root = Clear(m_Root); }

	~CBinarySearchTree() {
		Clear();
	}

	unsigned int Height() { return Height(m_Root); }

	unsigned int Height(Node<T>* node) {
		if (!node)
			return 0;

		unsigned int lH = Height(node->left);
		unsigned int rH = Height(node->right);

		return 1 + std::max(lH, rH);
	}

	Node<T>* InOrderSuccessor(Node<T>* node) {
		node = node->right;
		while (node && node->left) node = node->left;
		return node;
	}

	Node<T>* InOrderPredeccessor(Node<T>* node) {
		node = node->left;
		while (node && node->right) node = node->right;
		return node;
	}

	void Delete(int data) {
		m_Root = Delete(m_Root, data);
	}

private:
	Node<T>* m_Root;

	Node<T>* Insert(Node<T>* m_Root, T data);
	Node<T>* Delete(Node<T>* m_Root, T data);
	Node<T>* Clear(Node<T>* node) {
		if (!node) return nullptr;

		node->left = Clear(node->left);
		node->right = Clear(node->right);
		delete node;
		return nullptr;
	}

	void InOrder(Node<T>* node) {
		if (node) {
			InOrder(node->left);
			std::print("{} ", node->data);
			InOrder(node->right);
		}
	}

	void PreOrder(Node<T>* node) {
		if (node) {
			std::print("{} ", node->data);
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}

	void PostOrder(Node<T>* node) {
		if (node) {
			PostOrder(node->left);
			PostOrder(node->right);
			std::print("{} ", node->data);
		}
	}
};

template<class T>
Node<T>* CBinarySearchTree<T>::Insert(Node<T>* node, T data)
{
	if (nullptr == node)
		return new Node(data);

	if (data < node->data) {
		node->left = Insert(node->left, data);
		node->left->parent = node;
	}
	else {
		node->right = Insert(node->right, data);
		node->right->parent = node;
	}

	return node;
}

template<class T>
Node<T>* CBinarySearchTree<T>::Delete(Node<T>* node, T data)
{
	if (data < node->data) {
		node->left = Delete(node->left, data);
		if(node->left)
			node->left->parent = node;
	}
	else if (data > node->data) {
		node->right = Delete(node->right, data);
		if(node->right)
			node->right->parent = node;
	}
	else {
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}
		else if (!node->left) {
			Node<T>* rchild = node->right;
			delete node;
			return rchild;
		}
		else if (!node->right) {
			Node<T>* lchild = node->left;
			delete node;
			return lchild;
		}
		else {
			if (Height(node->left) > Height(node->right)) {
				Node<T>* pred = InOrderPredeccessor(node);
				std::swap(node->data, pred->data);
				node->left = Delete(node->left, pred->data);
				if (node->left)
					node->left->parent = node;
			}
			else {
				Node<T>* succ = InOrderSuccessor(node);
				std::swap(node->data, succ->data);
				node->right = Delete(node->right, succ->data);
				if (node->right)
					node->right->parent = node;
			}
		}
	}
	return node;
}
