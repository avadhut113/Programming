// RemoveValFromArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {

        for (std::vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            /*if (val == *itr)
                nums.erase(itr);*/
        }
        return nums.size();
    }
};

int test27()
{
    vector<int> vect{ 0,1,2,2,3,0,4,2 };
    Solution27 sl;
    sl.removeElement(vect,2);
}
