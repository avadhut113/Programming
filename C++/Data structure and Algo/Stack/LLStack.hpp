#pragma once
#include <iostream>

template <typename T>
class LLStack
{
	struct Node
	{
		T data;
		Node* next{ nullptr };
		Node(T _data):data(_data){}
	};
	Node* top{ nullptr };

	Node* clearStack(Node* top) {
		if (top == nullptr)
			return nullptr;
		top->next = clearStack(top->next);
		if (nullptr == top->next) {
			delete top;
			return nullptr;
		}
	}
public:
	LLStack() = default;
	void push(T data);
	T pop();
	friend std::ostream& operator<<(std::ostream& o, const LLStack<T>& stack)
	{
		LLStack<T>::Node* temp = stack.top;
		while (temp)
		{
			o << temp->data << " ";
			temp = temp->next;
		}
		o << "\n";
		return o;
	}

	void clear() { this->top = clearStack(this->top); }

	~LLStack() {

	}
};

template<typename T>
inline void LLStack<T>::push(T data)
{
	Node* newnode = new Node(data);
	newnode->next = top;
	top = newnode;
}

template<typename T>
inline T LLStack<T>::pop()
{
	if (nullptr == this->top) {
		std::cout << "Stack is empty \n";
		return -1;
	}
	Node* popNode = top;
	top = top->next;
	T data= popNode->data;
	return data;
}

//template <typename T>
//std::ostream& operator<<(std::ostream& o, const LLStack<T>& stack)
//{
//	LLStack<T>::Node* temp = stack.top;
//	while (temp)
//	{
//		o << temp->data << " ";
//	}
//	o << "\n";
//	return o;
//}