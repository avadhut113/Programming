#pragma once

template<int size>
void InsertionSort(int (&arr)[size])
{
  for (int i = 1; i < size; i++) {
    int value = arr[i];
    int hole = i;
    while (hole > 0 && arr[hole - 1] > value) {
      arr[hole] = arr[hole - 1];
      hole--;
    }
    arr[hole] = value;
  }
}