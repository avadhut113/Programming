#pragma once

template<int size>
void BubbleSort(int arr[])
{
  for (int i = 0; i < size; i++) {
    bool swap = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swap = true;
      }
    }

    if (!swap)
      break;
  }
}