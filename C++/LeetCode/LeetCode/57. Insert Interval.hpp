#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution57 {
public:
    static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::remove_reference<decltype(newInterval)>::type start_dummy = { -1,newInterval[0] };
        std::remove_reference<decltype(newInterval)>::type end_dummy = { newInterval[1], -1 };

        auto itr_start = std::lower_bound(intervals.begin(), intervals.end(), start_dummy, [](const vector<int>& a, decltype(a) b) { return a[1] < b[1]; });

        if (itr_start == intervals.end()) {
            intervals.emplace_back(newInterval);
        }

        auto itr_end = std::upper_bound(intervals.begin(), intervals.end(), end_dummy, [](const vector<int>& a, decltype(a) b) { return a[0] < b[0]; });

        if (itr_end == intervals.begin()) {
            intervals.emplace(intervals.begin(), newInterval);
        }

        itr_end = std::prev(itr_end);

        if (itr_start == itr_end) {
            *itr_start = { std::min((*itr_start)[0], newInterval[0]), std::max((*itr_start)[1], newInterval[1]) };
        } else if(itr_start < itr_end){
            vector<int> inserter = { std::min((*itr_start)[0], newInterval[0]), std::max((*itr_end)[1], newInterval[1]) };
            *itr_start = inserter;
            intervals.erase(itr_start + 1, itr_end + 1);
        }
        else {
            intervals.insert(itr_start, newInterval);
        }
        return intervals;
    }
};

void test57()
{
    vector<vector<int>> vect = {}/*{ {1,2},{3,5},{6,7},{8,10},{12,16} }*/;
    vector<int> v = { 4,8 };
    Solution57::insert(vect, v);
}