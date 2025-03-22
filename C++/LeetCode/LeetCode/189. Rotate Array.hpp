#pragma once
#include <iostream>
#include <vector>

class Solution189 {
public:
    // void rotate(vector<int>& nums, int k) {

    //     for(int i = 0 ; i < k ; i++) {
    //         int end = *(nums.end() - 1);
    //         nums.pop_back();
    //         nums.insert(nums.begin(), end);
    //     }
    // }

    // void rotate(vector<int>& nums, int k) {
    //     reverse(nums.begin(), nums.end());
    //     reverse(nums.begin(), nums.begin()+k);
    //     reverse(nums.begin()+k, nums.end());
    // }

    static void rotate(std::vector<int>& nums, int k) {
        std::vector<int> temp(k);
        int kpos = nums.size() - k;
        for (int i = 0; i < k; i++, kpos++) {
            temp[i] = nums[kpos];
        }

        kpos = nums.size() - 1;
        int i = 0;
        while (i < (nums.size() - k)) {
            nums[kpos] = nums[kpos - k];
            kpos--;
            i++;
        }

        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

void test189()
{
    std::vector<int> vect{ 1,2,3,4,5,6,7 };
    Solution189::rotate(vect, 3);

    std::vector<int> vect2{ -1,-100,3,99 };
    Solution189::rotate(vect, 2);
}