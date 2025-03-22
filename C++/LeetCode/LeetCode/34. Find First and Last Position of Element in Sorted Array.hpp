#pragma once
#include <iostream>
#include <vector>

class Solution34 {
public:
    static std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int N = nums.size();
        int l = 0, r = N - 1;
        int mid;
        bool faund = false;
        while (l <= r) {
            mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                faund = true;
                break;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (!faund)
            return { -1,-1 };

        int start = mid, end = mid;
        while (start > 0 && nums[start - 1] == nums[mid])
            start--;

        while (end < N - 1 && nums[end + 1] == nums[mid])
            end++;

        return { start, end };
    }
};

void test34()
{
    std::vector<int> vect{2,2};
    for (const auto& ele : Solution34::searchRange(vect,2)) { std::cout << ele; }
}