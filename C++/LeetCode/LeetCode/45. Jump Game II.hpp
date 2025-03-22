#pragma once
#include <vector>

class Solution45 {
public:
    static int jump(std::vector<int>& nums) {
        int numJumps = 0;
        int currentMaxReach = 0;
        int lastMaxReach = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            currentMaxReach = std::max(currentMaxReach, i + nums[i]);

            if (lastMaxReach == i) {
                numJumps++;
                lastMaxReach = currentMaxReach;
            }
        }

        return numJumps;
    }
};

void test45()
{
    std::vector<int> v{ 2,3,1,1,4 };
    //std::vector<int> v{ 2,3,0,1,4 };
    std::cout << Solution45::jump(v);
}