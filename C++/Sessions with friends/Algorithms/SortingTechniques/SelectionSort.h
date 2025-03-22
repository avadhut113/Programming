#pragma once

void selectionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}