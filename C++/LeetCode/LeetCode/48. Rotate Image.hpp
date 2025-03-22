#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution48 {
public:
    static void rotate(vector<vector<int>>& matrix) {
        auto start = matrix.begin();
        auto end = matrix.end() - 1;

        while (start < end) {
            std::swap(*start, *end);
            ++start;
            --end;
        }

        int rows = matrix.size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

void test48()
{
    //vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    Solution48::rotate(matrix);
}