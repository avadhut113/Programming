#pragma once
#include <algorithm>

int partition(int* arr, int low, int high);

void QuickSort(int* arr, int low, int high)
{
	if (low < high) {
		int part = partition(arr, low, high);
		QuickSort(arr,low, part);
		QuickSort(arr,part + 1, high);
	}
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[(low + high) / 2];
	int l = low-1;
	int h = high+1;

	while (true) {
		do 
			l++; 
		while (arr[l] < pivot);
			
		do
			h--;
		while (arr[h] > pivot);
			

		if (l >= h)
			return h;

		std::swap(arr[l], arr[h]);
	}
}