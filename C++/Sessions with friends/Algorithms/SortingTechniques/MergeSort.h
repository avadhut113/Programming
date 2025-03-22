#pragma once

void merge(int* arr,int low,int mid,int high);

void MergeSort(int* arr, int low, int high)
{
	if (low >= high)
		return;

	int mid = (low + high) / 2;

	MergeSort(arr, low, mid);
	MergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}

void merge(int* arr, int low, int mid, int high)
{
	int i, j, k;
	i = low;
	j = mid + 1;
	int size = high - low + 1;
	int* d = new int[size];
	k = 0;
	
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
			d[k++] = arr[i++];
		else
			d[k++] = arr[j++];
	}

	while (i <= mid)
		d[k++] = arr[i++];

	while (j <= high)
		d[k++] = arr[j++];

	for (int x = 0, y = low; x < size; x++, y++)
		arr[y] = d[x];

	delete[] d;
}