#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution918 {
public:

    //adding same array to the end and then applying kdane algo
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     const int N=nums.size();
    //     for(int i = 0; i < N; i++) {
    //         nums.emplace_back(nums[i]);
    //     }

    //     int maxSum = INT_MIN;
    //     int currSum= 0;

    //     for(const auto& i : nums) {
    //         currSum += i;
    //         maxSum = std::max(maxSum, currSum);
    //         currSum = currSum < 0 ? 0 : currSum;
    //     }
    //     return maxSum;
    // }

    /*static int maxSubarraySumCircular(vector<int>& nums) {
        int AvgSum = 0;
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for (const auto& i : nums) {
            AvgSum += (-i);
        }

        for(const auto& i : nums) {
            currSum += i;
            maxSum = std::max(maxSum, currSum);
            currSum = currSum < 0 ? 0 : currSum;
        }
        return -(AvgSum) + (maxSum);
    }*/

    static int kadane(vector<int>& A, int start, int end, int sign) {
        int cur = INT_MIN, ans = INT_MIN;

        for (int i = start; i <= end; i++) {
            cur = sign * A[i] + max(cur, 0);
            ans = max(ans, cur);
        }

        return ans;
    };

    static int maxSubarraySumCircular(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        int n = A.size();

        //1-interval
        int ans1 = kadane(A, 0, n - 1, 1);
        //2-intervals
        /*
        cannot set start as 0 and end as n-1,
        if so, we may choose the empty array
        */
        int tmp;
        /*
        The two intervals are [0...i] and [j...n-1]
        we need to make sure that the final subarray is not empty,
        that is, to make sure kadane algorithm don't give a subarray which is equal to A
        */
        int ans2 = ((tmp = kadane(A, 1, n - 1, -1)) == INT_MIN) ? INT_MIN : (tmp + sum);
        int ans3 = ((tmp = kadane(A, 0, n - 2, -1)) == INT_MIN) ? INT_MIN : (tmp + sum);

        return max({ ans1, ans2, ans3 });
    }
};

void test918()
{
    std::vector v{ 5,-3,5 };
    Solution918::maxSubarraySumCircular(v);
}