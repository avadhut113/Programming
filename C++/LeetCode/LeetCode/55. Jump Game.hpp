#pragma once
#include <vector>
#include <iostream>

class Solution55 {
public:
    static bool canJump(std::vector<int>& nums) {
        int maxReachable = 0; // Variable to keep track of the maximum reachable index so far

        // Iterate through each element of the vector
        for (int i = 0; i < nums.size(); ++i) {
            // If the current index is greater than the maximum reachable index, we can't proceed, return false
            if (maxReachable < i) {
                return false;
            }
            // Update maxReachable to the maximum of the current maxReachable and the current index plus its jump length
            maxReachable = std::max(maxReachable, i + nums[i]);
        }
        // If we are able to iterate through the entire vector, return true
        return true;
    }
};

void test55()
{
    //std::vector<int> v = { 2,3,1,1,4 };
    std::vector<int> v = { 3,2,1,0,4 };
    std::cout << std::boolalpha << Solution55::canJump(v);
}