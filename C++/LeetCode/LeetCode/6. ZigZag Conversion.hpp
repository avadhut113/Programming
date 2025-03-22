#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static string convert(string s, int numRows) {
        string ans;
        vector<vector<char>> rows(numRows);
        int k = 0;
        int direction = (numRows == 1) - 1;

        for (const char& c : s) {
            rows[k].emplace_back(c);
            if (k == 0 || k == numRows - 1)
                direction *= -1;
            k += direction;
        }

        for (const vector<char>& row : rows)
            for (const char& c : row)
                ans += c;

        return ans;
    }
};

void test_6()
{
    std::cout << Solution::convert("PAYPALISHIRING", 1) << std::endl;
    std::cout << Solution::convert("PAYPALISHIRING", 4) << std::endl;
    std::cout << Solution::convert("A", 1) << std::endl;
}