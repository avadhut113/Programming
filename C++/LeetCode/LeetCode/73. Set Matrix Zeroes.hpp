#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution73 {
public:
    static void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (0 == m) return;
        int n = matrix[0].size();
        if (0 == n) return;

        vector<bool> rows(m, false), cols(n, false);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    rows[i] = cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (rows[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            if (cols[j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

void test73()
{
    //vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };

    Solution73::setZeroes(matrix);

}