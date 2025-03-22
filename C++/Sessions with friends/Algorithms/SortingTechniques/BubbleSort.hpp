#pragma once


void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}