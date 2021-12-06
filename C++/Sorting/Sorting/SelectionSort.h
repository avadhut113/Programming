#pragma once

template<int size>
void SelectionSort(int arr[])
{
  for (int i = 0; i < size -1; i++) {
    int minloc = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minloc])
        minloc = j;
    }

    if (i != minloc) {
      int temp = arr[minloc];
      arr[minloc] = arr[i];
      arr[i] = temp;
    }
  }
}