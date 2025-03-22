// 88. Merge Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m+n);
        auto it_res = 0;
        auto it1 = 0, it2 = 0;

        while( it1 < m && it2 < n ) {
            if (nums1[it1] < nums2[it2]) {
                result[it_res] = nums1[it1];
                it1++;
            }
            else {
                result[it_res] = nums2[it2];
                it2++;
            }  
            it_res++;
        }

        while (it1 < m) {
            result[it_res] = nums1[it1];
            it_res++;
            it1++;
        }

        while (it2 < n) {
            result[it_res] = nums2[it2];
            it_res++;
            it2++;
        }

        nums1 = result;
    }
};

int test()
{
    Solution sl;
    vector<int> v1 = { -1, 0, 0, 3, 3, 3, 0, 0, 0 };
    vector<int> v2 = { 1, 2, 2 };
    sl.merge(v1, 6, v2, 3);
}

//[-1, 0, 0, 3, 3, 3, 0, 0, 0]
//6
//[1, 2, 2]
//3