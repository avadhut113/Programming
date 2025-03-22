#pragma once

template<typename T>
struct Node {
	T data;
	Node<T>* parent{ nullptr };
	Node<T>* left{ nullptr };
	Node<T>* right{ nullptr };
	int height{ 1 };

	Node<T>(T data) : data(data), left(nullptr), right(nullptr) {}
};