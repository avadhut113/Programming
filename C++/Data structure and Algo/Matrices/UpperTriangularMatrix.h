#pragma once
#pragma once
#include<iostream>

class UpperTriangularMatrix
{
	const int n;
	int* arr;
public:
	UpperTriangularMatrix(int size) : n(size) {
		int arr_size = n * (n + 1) / 2;
		arr = new int[arr_size];
	}

	void set_rows(int element, int i, int j) {
		if (i >= j)
			arr[i * (i - 1) / 2 + j - 1] = element;

	}

	int get_rows(int i, int j) {
		if (i >= j)
			return arr[i * (i - 1) / 2 + j - 1];
		else
			return 0;
	}

	void display_rowwise() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << get_rows(i, j) << " ";
			}
			std::cout << std::endl;
		}

	}

	void set_columns(int element, int i, int j) {
		if (i >= j)
			arr[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = element;

	}

	int get_columns(int i, int j) {
		if (i >= j)
			return arr[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
		else
			return 0;
	}

	void display_columnwise() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << get_columns(i, j) << " ";
			}
			std::cout << std::endl;
		}

	}

	~UpperTriangularMatrix() {
		delete[] arr;
		arr = nullptr;
	}
};