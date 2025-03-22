#include"pch.h"
#include <iostream>
#include<vector>
#include "MergeSort.h"
#include"bubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"


/*
Input : {9, 03, 83, 9, 2, 0, 1, 65, 2, 822, 9, 11, 22, 3, 3, 3, 47 }
Output : 0 1 2 2 3 3 3 3 9 9 9 11 22 47 65 83 822

Input : { -5, -6, -7, 0, 0, 0, 0, -8, 1, 2, 3 }
Output : -8 -7 -6 -5 0 0 0 0 1 2 3

Input : { -5, -7, 0, -8, 1, 65, 2, 822, 9, 11, 22, 3, 47 }
Output :

Input : {-3, -2, -1, -9, -5, -1, -19, -33 }
Output : -33 -19 -9 -5 -3 -2 -1 -1

Input :
Output :
*/


int main()
{
  int arr[] = { -5, -7, 0, -8, 1, 65, 2, 822, 9, 11, 22, 3, 47 };
  int SortedArr[100];
  int size = sizeof(arr) / sizeof(int);

  //BubbleSort(arr);
  //SelectionSort(arr);
  //InsertionSort(arr);


  //for (int k = 0; k < size; k++)
  //  SortedArr[k] = arr[k];

  //mergeSort(arr, 0, size);

  QuickSort(arr, 0, size-1);

  for (auto i : arr)
    std::cout << i << std::endl;

}