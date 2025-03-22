#pragma once
#include <iostream>
#include <vector>
#include <format>

using namespace std;

class Solution35 {
public:
    static int binarySearch(vector<int>& nums, int target, int l, int h)
    {
        if (l <= h) {
            int mid = (l + h) / 2;

            if (nums[mid] == target)
                return mid;

            if (target < nums[mid])
                return binarySearch(nums, target, l, mid - 1);

            return binarySearch(nums, target, mid + 1, h);
        }
        return l;
    }

    static int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

void test35()
{
    std::vector v{ 1,3,5,6 };
    //std::format("{} , {} \n", "Output : ", Solution35::searchInsert(v, 5));
    std::cout << Solution35::searchInsert(v, 2) << "\n";
}