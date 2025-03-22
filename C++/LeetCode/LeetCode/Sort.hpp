#pragma once
#include <iostream>
#include <vector>


auto bubblesort(const std::vector<int>& vect)/*->decltype(vect)*/
{
    std::vector<int> res(vect);

    for (int i = 0; i < res.size() - 1; i++) {
        int flag = true;
        for (int j = 0; j < res.size() - i - 1; j++) {
            if (res[j + 1] < res[j]) {
                std::swap(res[j], res[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
    return res;
}

auto selectionSort(const std::vector<int>& vect)
{
    std::vector<int> res(vect);

    for (int i = 0; i < res.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < res.size(); j++) {
            if (res[j] < res[min]) {
                min = j;
            }
        }
        if (i != min)
            std::swap(res[i], res[min]);

    }
    return res;
}

auto insertionSort(const std::vector<int>& vect)
{
    std::vector<int> res(vect);

    for (int i = 1; i < res.size(); i++) {
        int j = i - 1;
        int ele = res[i];
        while (j >= 0 && res[j] > ele) {

            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = ele;
    }
    return res;
}
// 9 8 7 6 4

int partition(std::vector<int>& vect, int low, int high)
{
    int l = low - 1;
    int h = high + 1;
    int mid = vect[(low + high) / 2];

    while (true) {
        do {
            l++;
        } while (vect[l] < mid);

        do {
            h--;
        } while (vect[h] > mid);

        if (l >= h)
            return h;

        std::swap(vect[l], vect[h]);
    }
}

void quickSort(std::vector<int>& vect, int low, int high)
{
    if (low < high) {
        int part = partition(vect, low, high);
        quickSort(vect, low, part);
        quickSort(vect, part + 1, high);
    }
}

void Merge(std::vector<int>& vect, int left, int mid, int right)
{
    std::vector<int> result(right - left + 1);
    int i = left, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (vect[i] <= vect[j]) {
            result[k] = vect[i];
            i++;
        }
        else {
            result[k] = vect[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        result[k] = vect[i];
        i++; k++;
    }

    while (j <= right) {
        result[k] = vect[j];
        j++; k++;
    }

    for (int i = 0; i < result.size(); i++) {
        vect[i + left] = result[i];
    }
}

void MergeSort(std::vector<int>& vect, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(vect, left, mid);
        MergeSort(vect, mid + 1, right);
        Merge(vect, left, mid, right);
    }
}

void print_sort()
{
    std::vector<int> input;
    for (int i = 0; i < 40; i++)
        input.emplace_back(std::rand() % 100);

    for (const auto& ele : input) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
    //auto res = bubblesort(input);
    //auto res = selectionSort(input);
    //auto res = insertionSort(input);

    std::vector<int> res(input);
    //quickSort(res, 0, res.size() - 1);
    MergeSort(res, 0, res.size() - 1);

    for (const auto& ele : res) {
        std::cout << ele << " ";
    }
    std::cout << "\n";
}