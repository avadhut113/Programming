#pragma once
#include<initializer_list>

template<typename T,size_t s = 5>
class Stack
{
public:
	Stack();
	Stack(int size);
	Stack(std::initializer_list<T> init_list) {
		size = init_list.size();
		arr = new T[size];
		for (auto& ele : init_list) {
			push(std::move(ele));
		}
	}
	void push(const T& element);
	int pop();
	int top() { return arr[m_top]; }
	bool IsEmpty() { return m_top == -1; }
	bool IsFull() { return m_top == (size - 1); }
	void display();
private:
	T* arr{nullptr};
	int m_top{ -1 };
	size_t size{s};
};

template<typename T, size_t s>
inline Stack<T, s>::Stack()
{
	arr = new T[s];
	this->size = s;
}

template<typename T, size_t s>
inline Stack<T, s>::Stack(int size)
{
	arr = new T[size];
	this->size = size;
}

template<typename T, size_t s>
inline void Stack<T, s>::push(const T& element)
{
	if (IsFull())
		std::cout << "stack is full element : " << element << "  not inserted." << std::endl;
	else {
		m_top++;
		arr[m_top] = element;
	}
}

template<typename T, size_t s>
inline int Stack<T, s>::pop()
{
	if (IsEmpty())
		std::cout << "stack is empty" << std::endl;
	else {
		return arr[m_top--];
	}
	return -1;
}

template<typename T, size_t s>
inline void Stack<T, s>::display()
{
	std::cout << "--------------------------" << std::endl;
	for (int index = 0; index <= m_top; index++) {
		std::cout << "stack[" << index << "] = " << arr[index] << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}

