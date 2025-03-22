// MaximumSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int DivideConcure(int i, int j, vector<int>& nums)
{
    if (i == j) return nums[i];
    int left_cross = INT_MIN, right_cross = INT_MIN;
    int mid = (i + j) / 2;
    int cur = 0;
    for (int k = mid + 1; k <= j; k++)
    {
        cur += nums[k];
        right_cross = max(right_cross, cur);
    }
    cur = 0;
    for (int k = mid; k >= i; k--)
    {
        cur += nums[k];
        left_cross = max(left_cross, cur);
    }
    int cross_sum = left_cross + right_cross;
    int left_sum = DivideConcure(i, mid, nums);
    int right_sum = DivideConcure(mid + 1, j, nums);
    return max(cross_sum, max(left_sum, right_sum));
}

int maxSubArray(vector<int>& nums)
{
    return DivideConcure(0,nums.size() - 1,nums);
}


// Broute fource 
// Time conplexity O(n3)
/*int maxSubArray(vector<int>& nums)
{

    int largSum = *(min(nums.begin(), nums.end()));
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];

            if (largSum < sum)
                largSum = sum;
        }
    }
    return largSum;
}*/



int test()
{
    vector<int> vect{ -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(vect);
}
