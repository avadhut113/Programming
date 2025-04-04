#pragma once
#include <vector>

using namespace std;

class Solution46 {
public:
    void backtrack(vector<vector<int>>& pers, vector<int>& per, vector<int>& nums) {
        if (per.size() == nums.size()) {
            pers.push_back(per);
        }
        else {
            for (int e : nums) {
                if (find(per.begin(), per.end(), e) != per.end()) {
                    continue;
                }
                per.push_back(e);
                backtrack(pers, per, nums);
                per.pop_back();
            }
        }
    };

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> pers;
        vector<int> per;

        backtrack(pers, per, nums);

        return pers;
    }
};

void test46()
{
    Solution46 sl;
    std::vector<int> v{ 1,2,3 };
    sl.permute(v);
}