#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Solution274 {
public:
    static int hIndex(std::vector<int>& citations) {
        std::sort(citations.rbegin(), citations.rend());
        int h = 0;
        while (h < citations.size() and citations[h] >= h + 1) {
            h++;
        }
        return h;
    }
};

void test274()
{
    //std::vector<int> v{ 3,0,6,1,5 };
    std::vector<int> v{ 1,3,1 };
    std::cout << Solution274::hIndex(v);
}