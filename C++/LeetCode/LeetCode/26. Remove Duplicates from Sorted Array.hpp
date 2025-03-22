// RemoveDupSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution26 {
public:
    static int removeDuplicates(vector<int>& nums) {

        /*nums.erase(
            std::unique(nums.begin(), nums.end()),
            nums.end());*/

        /*set<int> s;
        for (unsigned i = 0; i < nums.size(); i++) s.insert(nums[i]);
        nums.assign(s.begin(), s.end());*/

        std::vector<int>::iterator it_i = nums.begin();
        while (it_i != nums.end()) {
            std::vector<int>::iterator it_j = it_i +1;

            while(it_j != nums.end() && *it_i == *it_j) {
                it_j++;               
            }
            nums.erase(it_i+1, it_j);
            it_i++;
        }

        return nums.size();
    }

    /*int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        int left = 1;

        for (int right = 1; right < N; right++) {
            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }*/
};

int test26()
{
    std::vector<int> vect{ 1,1,2 };
    Solution26::removeDuplicates(vect);
}
