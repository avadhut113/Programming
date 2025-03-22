#pragma once
#include <iostream>
#include <ostream>

template <class T>
class SinglyLinkedList
{
	struct Node {
		T data{0};
		Node* next{nullptr};

		Node(T _data) : data(_data) {};
	};

	Node* head{ nullptr };
public:
	SinglyLinkedList() = default;
	void insert(int pos, T data) {
		Node* newnode = new Node(data);
		Node* curr = head;

		for (int i = 0; i < pos-2; i++) {
			if (nullptr == curr) {
				std::cout << "invalid position\n";
				return;
			}
			curr = curr->next;
		}
		newnode->next = curr->next;
		curr->next = newnode;
	}

	void insertData(T data) {
		Node* newnode = new Node(data);
		if (nullptr == head) {
			head = newnode;
			return;
		}
		Node* curr = head;
		while (curr->next != nullptr)
			curr = curr->next;

		curr->next = newnode;
	}

	void remove(int pos) {
		if (nullptr == head) {
			std::cout << "List is Empty\n";
			return;
		}

		Node* curr = head;
		if (1 == pos) {
			head = head->next;
			delete curr;
			return;
		}

		Node* prev{ curr };
		int currpos = 1;
		while (curr && currpos < pos) {
			prev = curr;
			curr = curr->next;
			currpos++;
		}
		if (curr) {
			prev->next = curr->next;
			delete curr;
		}
		else {
			std::cout << pos << " position is invalid\n";
		}
	}

	void removeData(T data) {
		if (nullptr == head) {
			std::cout << "List is Empty\n";
			return;
		}
		Node* curr = head;
		if (head->data == data) {
			head = head->next;
			delete curr;
			return;
		}

		Node* prev{ curr };
		while (curr && curr->data != data) {
			prev = curr;
			curr = curr->next;
		}
		if (curr) {
			prev->next = curr->next;
			delete curr;
		}
		else {
			std::cout << data <<" not found\n";
		}
	}

	bool isSorted()
	{
		if (nullptr == head) {
			std::cout << "List is Empty\n";
			return false;
		}

		Node* curr = head;
		while (curr->next) {
			if (curr->next->data < curr->data)
				return false;

			curr = curr->next;
		}
		return true;
	}

	void insertInSortedList(T data)
	{
		if (!isSorted()) {
			std::cout << "List is not sorted\n";
			return;
		}
		Node* newnode = new Node(data);
		if (head->data > data) {
			newnode->next = head;
			head = newnode;
			return;
		}

		Node* curr = head;
		while (curr->next && curr->next->data < data) {
			curr = curr->next;
		}
		newnode->next = curr->next;
		curr->next = newnode;
	}

	friend std::ostream& operator<<(std::ostream& out, SinglyLinkedList<T>& sll) {

		if (nullptr == sll.head) {
			out << "List is Empty\n";
			return out;
		}
		Node* curr = sll.head;
		while (curr) {
			out << curr->data << " ";
			curr = curr->next;
		}
		out << "\n";
		return out;
	}

	Node* reverse(Node* node) {
		if (node->next) {
			node->next = node->next->next;
			node = reverse(node->next);
			return node;
		}
	}

	void reverseList() {
		head = reverse(head);
	}

	friend void MergeListInsorted(SinglyLinkedList<T>& sll1, SinglyLinkedList<T>& sll2);

	void clear() {
		Node* curr = head;
		while (curr) {
			head = head->next;
			delete curr;
			curr = head;
		}
	}
	~SinglyLinkedList() {
		clear();
	}
};

template<typename T>
void MergeListInsorted(SinglyLinkedList<T>& sll1, SinglyLinkedList<T>& sll2)
{

}