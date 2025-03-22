#pragma once
#include <iostream>

template <typename T>
class SinglyLinkList
{
	struct Node
	{
		T m_data;
		Node* next{ nullptr };

		Node(T data) :m_data(data) {}
	};

	Node* head{ nullptr };

	void reverseRecursion(Node* prev, Node* curr);
public:
	SinglyLinkList() = default;
	~SinglyLinkList() { clear(); }

	void push_back(T data);
	void insert(T data, int location);
	void clear();
	void reverse();
	void reverse_recursion();
	bool isLoop();



	friend std::ostream& operator<<(std::ostream& os, SinglyLinkList<T>& sl)
	{
		Node* temp = sl.head;
		while (temp) {
			os << temp->m_data << " ";
			temp = temp->next;
		}
		os << std::endl;
		return os;
	}

	friend Node* MergeSortedList(SinglyLinkList<T>& sl1, SinglyLinkList<T>& sl2)
	{
		Node* sl1ptr = sl1.head;
		Node* sl2ptr = sl2.head;

		Node* newList = nullptr, * last = nullptr;

		if (sl1ptr->m_data < sl2ptr->m_data) {
			newList = last = sl1ptr;
			sl1ptr = sl1ptr->next;
			last->next = nullptr
		}
		else {
			newList = last = sl2ptr;
			sl2ptr = sl2ptr->next;
			last->next = nullptr
		}

		while (sl1ptr != nullptr && sl2ptr != nullptr) {
			if (sl1ptr->m_data < sl2ptr->m_data) {
				last->next = sl1ptr;
				last = sl1ptr;
				sl1ptr = sl1ptr->next;
				last->next = nullptr
			}
			else {
				last->next = sl2ptr;
				last = sl2ptr;
				sl2ptr = sl2ptr->next;
				last->next = nullptr
			}
		}

		if(sl1ptr != nullptr)
			last->next = sl1ptr;
		else
			last->next = sl2ptr;
	}

};

