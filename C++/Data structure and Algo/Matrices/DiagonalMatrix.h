#pragma once
#include <iostream>

class DiagonalMatrix
{
	const int n;
	int* arr;
public:
	DiagonalMatrix(int size) : n(size), arr(new int[n]) {
	}

	void set(int element,int i,int j) {
		if (i == j)
			arr[i] = element;
	}

	int get(int i,int j) {
		if (i == j)
			return arr[i];
		else
			return 0;
	}

	void display() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << get(i, j) << " ";
			}
			std::cout << std::endl;
		}

	}

	~DiagonalMatrix() { delete[] arr; }
};