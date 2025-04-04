#pragma once
#include <vector>

class Solution33 {
public:
    static int findMinIdx(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums.back()) {
                //ex: [4,5,6,7,0,1,2], 7 > 2
                //so search in right part
                l = mid + 1;
            }
            else {
                //right part is monotonic,
                //so search in left part
                r = mid - 1;
            }
        }

        return l;
    };

    static int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int minIdx = findMinIdx(nums);
        if (nums[minIdx] == target) return minIdx;

        // cout << "minIdx: " << minIdx << endl;

        //this is the important part!!
        int l, r;
        if (nums[n - 1] >= target) {
            //we can find target in left part
            l = minIdx + 1;
            r = n - 1;
        }
        else {
            //we can find target in left part
            l = 0;
            r = minIdx - 1;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};

void test33()
{
    std:vector<int> vect = { 4,5,6,7,0,1,2 };
    std::cout << Solution33::search(vect, 6) <<"\n";
}