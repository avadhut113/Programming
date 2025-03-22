#pragma once
#include <iostream>
#include <string>
#include <format>
#include <ostream>
#include <vector>

using namespace std;

class Solution_10 {
public:
    string s, p;
    vector<vector<int>> memo;

    bool dfs(int i, int j) {
        //i for s, j for p
        if (j == p.size()) return i == s.size();

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // cout << i << " " << j << endl;

        bool first_match = (i < s.size()) && (p[j] == '.' || p[j] == s[i]);

        if (j + 1 < p.size() && p[j + 1] == '*') {
            memo[i][j] = (first_match && dfs(i + 1, j)) ||
                dfs(i, j + 2);
        }
        else {
            memo[i][j] = first_match && dfs(i + 1, j + 1);
        }

        return memo[i][j];
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0);
    }
};

void test_10()
{
    Solution_10 sl;
    std::cout << std::boolalpha << sl.isMatch("abcabc", ".b.a*") << std::endl;
}