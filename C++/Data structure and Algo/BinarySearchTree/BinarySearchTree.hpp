#include "Node.hpp"
#include <iostream>
#include <initializer_list>
#include <stack>
#include <queue>

template<typename T>
class CBinarySearchTree
{
	Node<T>* SearchRecursion(T data, Node<T>* curr);
	Node<T>* InsertRecursion(T i, Node<T>* p);
	Node<T>* DeleteRecursive(Node<T>* node, T data);
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

	void InOrderTraversal(Node<T>* node) const noexcept
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

	Node<T>* m_root = nullptr;

public:

	CBinarySearchTree() = default;
	CBinarySearchTree(std::initializer_list<T> list) 
	{
		for (const auto item : list) {
			InsertIterative(item);
		}
	}
	~CBinarySearchTree() = default;

	//Search data and return pointer to data node
	Node<T>* SearchIteration(T data);	
	Node<T>* SearchRecursion(T data);

	//Insert data
	Node<T>* InsertIterative(T data);
	Node<T>* InsertRecursion(T i);

	//Delete Node
	void DeleteIterative(T data);
	void DeleteRecursive(T data);

	//Tree Traversal Recursive
	void InOrderTraversal() { InOrderTraversal(m_root); std::cout << std::endl; }
	void PreOrderTraversal() { PreOrderTraversal(m_root); std::cout << std::endl; }
	void PostOrderTraversal() { PostOrderTraversal(m_root); std::cout << std::endl; }

	//Tree Traversal Iterative
	void inOrderIterative();
	void PreOrderIterative();
	void PostOrderIterative();

	//level order traversal
	void levelOrderTraversal();

	int countRecursive();
	int countIterative();

	int heightIterative();
	int heightRecursive();
};


template<typename T>
Node<T>* CBinarySearchTree<T>::SearchIteration(T data)
{
	Node<T>* curr = m_root;

	while (curr != nullptr) {
		if (curr->data == data)
			return curr;

		if (curr->data < data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	return nullptr;
}

template<typename T>
Node<T>* CBinarySearchTree<T>::SearchRecursion(T data, Node<T>* curr)
{
	if (curr->data == data)
		return curr;

	if (data < curr->data)
		SearchRecursion(data, curr->left);
	else
		SearchRecursion(data,curr->right);

	return nullptr;
}

template<typename T>
Node<T>* CBinarySearchTree<T>::SearchRecursion(T data)
{
	return SearchRecursion(data, m_root);
}

template<typename T>
Node<T>* CBinarySearchTree<T>::InsertIterative(T data)
{
	Node<T>* curr = nullptr;
	Node<T>* parent = nullptr;

	curr = m_root;
	while (curr != nullptr) {
		if (curr->data == data)
			return curr;

		parent = curr;

		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	Node<T>* newNode = new Node<T>(data);
	if (nullptr == m_root) {
		m_root = newNode;
		newNode->parent = parent;
		return newNode;
	}

	if (parent->data < newNode->data)
		parent->right = newNode;
	else
		parent->left = newNode;

	newNode->parent = parent;

	return newNode;
}

template<typename T>
Node<T>* CBinarySearchTree<T>::InsertRecursion(T i, Node<T>* p)
{
	if (!p)
		return new Node<T>(i);

	else if (i < p->data) {
		p->left = InsertRecursion(i, p->left);
		p->left->parent = p;
	}
	else if (i > p->data) {
		p->right = InsertRecursion(i, p->right);
		p->right->parent = p;
	}

	return p;
}

template<typename T>
Node<T>* CBinarySearchTree<T>::InsertRecursion(T data)
{
	return InsertRecursion(data, m_root);
}

//template<typename T>
//Node<T>* Inordersuccessor(const Node<T>* node)
//{
//	Node<T>* temp = node;
//	while (temp && temp->left)
//		temp = temp->left;
//
//	return temp;
//}

//template<typename T>
//Node<T>* InorderPredecessor(const Node<T>* node)
//{
//	Node<T>* temp = node;
//	while (temp && temp->right)
//		temp = temp->right;
//
//	return temp;
//}

template<typename T>
Node<T>* CBinarySearchTree<T>::DeleteRecursive(Node<T>* node,T data)
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
	return node;
}

template<typename T>
void CBinarySearchTree<T>::DeleteRecursive(T data)
{
	m_root = DeleteRecursive(m_root, data);
}

template<typename T>
void CBinarySearchTree<T>::DeleteIterative(T data)
{
	Node<T> *curr{ m_root }, *parent{m_root};
	
	while (curr && curr->data != data) {
		parent = curr;
		if (data < curr->data) curr = curr->left;
		else curr = curr->right;
	}

	if (nullptr == curr) {
		std::cout << "Data is not preset" << std::endl;
		return;
	}

	if (nullptr == curr->left || nullptr == curr->right) {
		Node<T>* new_curr{ curr };
		if (nullptr == curr->left)
			new_curr = curr->right;
		else
			new_curr = curr->left;

		if (!parent) {
			m_root = new_curr;
			new_curr->parent = nullptr;
			return;
		}


		if (curr == parent->left)
			parent->left = new_curr;
		else
			parent->right = new_curr;

		new_curr->parent = parent;

		delete curr;
		return;
	}
	else {
		Node<T> *temp{ nullptr }, *p{ nullptr };
		bool isSuccesor{ false };

		if (heightRecursive(curr->left) < heightRecursive(curr->right)) {
			isSuccesor = true;
			temp = curr->right;
			while (temp && temp->left) {
				p = temp;
				temp = temp->left;
			}
		}
		else {
			temp = curr->left;
			while (temp && temp->right) {
				p = temp;
				temp = temp->right;

			}
		}

		curr->data = temp->data;

		if (isSuccesor) {
			if (p)
				p->left = temp->right;
			else
				curr->right = temp->right;
		} else {
			if (p)
				p->right = temp->left;
			else
				curr->left = temp->left;
		}


		delete temp;
	}
}

//Iterative function for inorder tree traversal
template<typename T>
void CBinarySearchTree<T>::inOrderIterative()
{
	std::stack<Node<T>*> s;
	Node<T>* curr = m_root;

	while (curr != NULL || s.empty() == false) {

		// Reach the left most Node of the
		// curr Node
		while (curr != NULL) {

			// Place pointer to a tree node on
			// the stack before traversing
			// the node's left subtree
			s.push(curr);
			curr = curr->left;
		}

		// Current must be NULL at this point
		curr = s.top();
		s.pop();

		std::cout << curr->data << " ";

		// we have visited the node and its
		// left subtree.  Now, it's right
		// subtree's turn
		curr = curr->right;

	}

	std::cout << std::endl;
}

//Iterative function for Preorder tree traversal
template<typename T>
void CBinarySearchTree<T>::PreOrderIterative()
{
	std::stack<Node<T>*> s;
	Node<T>* curr = m_root;

	while (curr != NULL || s.empty() == false) {

		// Reach the left most Node of the
		// curr Node
		while (curr != NULL) {

			//print the node and go to left
			std::cout << curr->data << " ";

			// Place pointer to a tree node on
			// the stack before traversing
			// the node's left subtree
			s.push(curr);
			curr = curr->left;
		}

		// Current must be NULL at this point
		curr = s.top();
		s.pop();

		// we have visited the node and its
		// left subtree.  Now, it's right
		// subtree's turn
		curr = curr->right;

	}

	std::cout << std::endl;
}

//Iterative function for inorder tree traversal
template<typename T>
void CBinarySearchTree<T>::PostOrderIterative()
{
	std::stack<Node<T>*> s1,s2;
	if (m_root == NULL)
		return;

	// push root to first stack 
	s1.push(m_root);
	Node<T>* curr;

	// Run while first stack is not empty 
	while (!s1.empty()) {
		// Pop an item from s1 and push it to s2 
		curr = s1.top();
		s1.pop();
		s2.push(curr);

		// Push left and right children 
		// of removed item to s1 
		if (curr->left)
			s1.push(curr->left);
		if (curr->right)
			s1.push(curr->right);
	}

	// Print all elements of second stack 
	while (!s2.empty()) {
		curr = s2.top();
		s2.pop();
		std::cout << curr->data << " ";
	}

	std::cout << std::endl;
}

template<typename T>
inline void CBinarySearchTree<T>::levelOrderTraversal()
{
	std::queue<Node<T>*> q;
	q.push(m_root);

	while (!q.empty()) {
		Node<T>* curr = q.front();
		q.pop();

		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);

		std::cout << curr->data << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline int CBinarySearchTree<T>::countRecursive()
{
	return countRecursive(m_root);
}

template<typename T>
inline int CBinarySearchTree<T>::countIterative()
{
	Node<T>* curr = m_root;
	int count{ 0 };
	std::stack<Node<T>*> s;
	while (curr || !s.empty()) {
		while (curr)
		{
			s.push(curr);
			curr = curr->left;
			count++;
		}
		curr = s.top();
		s.pop();

		curr = curr->right;
	}
	return count;
}

template<typename T>
inline int CBinarySearchTree<T>::heightIterative()
{
	std::queue<Node<T>*> nodesInLevel;
	int height = 0;
	size_t nodeCount = 0; // Calculate  number of nodes in a level.
	Node<T>* currentNode; // Pointer to store the address of a

	// node in the current level.
	if (m_root == NULL) {
		return 0;
	}
	nodesInLevel.push(m_root);
	while (!nodesInLevel.empty()) {
		// This while loop runs for every level and
		// increases the height by 1 in each iteration. If
		// the queue is empty then it implies that the last
		// level of tree has been parsed.
		height++;
		// Create another while loop which will insert all
		// the child nodes of the current level in the
		// queue.

		nodeCount = nodesInLevel.size();
		while (nodeCount--) {
			currentNode = nodesInLevel.front();

			// Check if the current nodes has left child and
			// insert it in the queue.

			if (currentNode->left != NULL) {
				nodesInLevel.push(currentNode->left);
			}

			// Check if the current nodes has right child
			// and insert it in the queue.
			if (currentNode->right != NULL) {
				nodesInLevel.push(currentNode->right);
			}

			// Once the children of the current node are
			// inserted. Delete the current node.

			nodesInLevel.pop();
		}
	}
	return height;
}

template<typename T>
inline int CBinarySearchTree<T>::heightRecursive()
{
	return heightRecursive(m_root);
}
