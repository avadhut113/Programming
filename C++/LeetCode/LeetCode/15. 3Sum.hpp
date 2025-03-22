#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution15 {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int len=nums.size();
    //     if(len==0 || len<3) 
    //         return {};
    //     set<vector<int>> s; 
    //     sort(nums.begin(),nums.end());

    //     for(int i=0;i<len-2;i++){
    //         for(int j=i+1;j<len-1;j++){
    //             for(int k=j+1;k<len;k++){
    //                 if(nums[i]+nums[j]+nums[k]==0){
    //                     s.insert({nums[i],nums[j],nums[k]});
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> ans(s.begin(),s.end());
    //     return ans;
    // }

    static vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        int N = nums.size();
        for (int left = 0; left <= N - 3; left++) {
            int mid = left + 1, right = N - 1;
            while (mid < right) {
                if (nums[left] + nums[mid] + nums[right] == 0) {
                    res.insert({ nums[left],nums[mid],nums[right] });
                    mid++;
                    right--;
                }
                else if (nums[left] + nums[mid] + nums[right] < 0)
                    mid++;
                else
                    right--;
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

void test15()
{
    vector<int> v{0,0,0};
    Solution15::threeSum(v);
}