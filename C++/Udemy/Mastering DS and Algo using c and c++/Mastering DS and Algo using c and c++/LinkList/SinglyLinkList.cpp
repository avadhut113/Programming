#include "SinglyLinkList.h"

template<typename T>
void SinglyLinkList<T>::push_back(T data) {
	Node* newnode = new Node(data);

	if (head == nullptr) {
		head = newnode;
		return;
	}

	Node* temp = head;
	while (temp->next)
		temp = temp->next;

	temp->next = newnode;
	return;
}

template<typename T>
void SinglyLinkList<T>::insert(T data, int location)
{
	Node* newnode = new Node(data);

	if (head == nullptr) {
		head = newnode;
		return;
	}

	Node* temp = head, * prev = head;
	for (int i = 0; i < location - 1 && temp; i++)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = newnode;
	newnode->next = temp;
	return;
}

template<typename T>
void SinglyLinkList<T>::clear()
{
	Node *temp = head,*prev = head;
	while (temp) {
		prev = temp;
		temp = temp->next;
		delete prev;
	}
	head = nullptr;
}

template<typename T>
void SinglyLinkList<T>::reverse()
{
	Node *curr = nullptr, *prev = nullptr, *forward=head;

	while (forward) {
		prev = curr;
		curr = forward;
		forward = forward->next;

		curr->next = prev;
	}

	head = curr;
}

template<typename T>
void SinglyLinkList<T>::reverseRecursion(Node* prev, Node* curr)
{
	if (curr != nullptr) {
		reverseRecursion(curr, curr->next);
		curr->next = prev;
	}
	else
	{
		head = prev;
	}
}

template<typename T>
void SinglyLinkList<T>::reverse_recursion()
{
	reverseRecursion(nullptr, head);
}

template<typename T>
bool SinglyLinkList<T>::isLoop()
{
	return nullptr;
}
