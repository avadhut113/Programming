#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution228 {
public:
    static vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<string>();
        int start = nums[0], end = nums[0];
        vector<string> ans;
        for (int i = 1; i < n; i++) {
            // if(nums[i] - end == 1){
            if (end != INT_MAX && nums[i] == end + 1) { //avoid overflow
                //extend old range
                end = nums[i];
            }
            else {
                //new range
                if (start == end)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(end));
                start = end = nums[i];
            }
        }

        //handle the last interval and when n is equal to 1
        if (start == end)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(end));

        return ans;
    }
};

void test228()
{
    std::vector<int> vect{ 0,1,2,4,5,7 };
    Solution228::summaryRanges(vect);
}