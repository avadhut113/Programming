#pragma once
#include <vector>

class Solution162 {
public:
    static int findPeakElement(std::vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + ((r - l) >> 1);

            // cout << l << ", " << mid << ", " << r << endl;

            if (nums[mid] > nums[mid + 1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        //now l is equal to r
        //return r; //works
        return l; //works
    }
};

void test162()
{
    std::vector<int> vect = { 1,2,1,3,5,6,4 };
    Solution162::findPeakElement(vect);
}