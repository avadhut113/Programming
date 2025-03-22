// SortingTechniques.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.h"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "MergeSort.h"
#include <array>
#include <forward_list>

std::forward_list<int> list1;
std::forward_list<int> list2;
int sum = { 0 };
int expo = 0;
bool carry = false;

void addlinklist(std::forward_list<int>::iterator itr1, std::forward_list<int>::iterator itr2)
{
    bool ishead = false;
    if (itr1 == list1.begin()) {
        ishead = true;
    }
    if (itr1 == list1.end() && itr2 == list2.end())
        return;
    
    int num1 = *itr1++, num2 = *itr2++;
    addlinklist(itr1, itr2);
    int cursum{ 0 };
    if (carry) {
        cursum = num1 + num2 + 1;
        carry = false;
    } else{
        cursum = num1 + num2;
    }

    if (cursum >= 10 && !ishead)
    {
        cursum = cursum % 10;
        sum += std::pow(10, expo++) * cursum;
        carry = true;
    } else {
        sum += std::pow(10, expo++) * cursum;
    }
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void my_alloc(int** ptr)
{
    *ptr = new int;
}

void set_int(int* ptr_a)
{
    *ptr_a = 10; 
}

void set_int_to(int* ptr_a)
{
    *ptr_a = 10;
}

int main()
{

    /*int a = 0;
    set_int(&a);
    std::cout << a;

    int* t = { nullptr };
    my_alloc(&t);
    *t = 30;
    std::cout << *t;*/

    int* t = new int(0);
    set_int_to(t);

    /*list1 = { 1,2,3,4,5 };
    list2 = { 9,8,7,6,5 };
    addlinklist(list1.begin(),list2.begin());
    std::cout << sum << std::endl;*/
    //int arr[] = { 42,78,12,56,89,2,112 };
    //insertionSort(arr, 5);
    //bubbleSort(arr, 5);
    //selectionSort(arr, 5);
    //print(arr,5);
    //QuickSort(arr, 0, 6);
    //print(arr, 7);

    /*std::array<int,100> arr{};
    std::generate(std::begin(arr), std::end(arr), []() {
        return rand() % 100;
        });*/

    //constexpr int size = 200;
    //int arr[size] = {};
    //for (int i = 0; i < size; i++)
    //    arr[i] = rand() % 100;

    //std::cout << "Before sort :" << std::endl;
    //print(arr, size);

    //MergeSort(arr, 0, size-1);
    //std::cout << std::endl;
    //std::cout << std::endl;

    //std::cout <<"After sort :" << std::endl;
    //print(arr, size);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
