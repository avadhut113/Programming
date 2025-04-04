#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution56 {
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        sort(intervals.begin(), intervals.end());

        int i = 1;
        while (i < intervals.size()) {
            // cout << i << " ";
            //last end >= current start
            if (intervals[i - 1][1] >= intervals[i][0]) {
                //merge them
                intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
            else {
                i++;
            }
        }

        return intervals;
    }
};

void test56()
{
    std::vector<std::vector<int>> v{ {1,3},{2,6},{8,10},{15,18} };
    Solution56::merge(v);
}