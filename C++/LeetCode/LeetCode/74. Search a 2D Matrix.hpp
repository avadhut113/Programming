#pragma once
#include <vector>

class Solution74 {
public:
    static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        unsigned int m = matrix.size();
        if (m == 0) return false;
        unsigned int n = matrix[0].size();

        unsigned int l = 0, h = m * n - 1;

        while (l <= h) {
            unsigned int mid = (l + h) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }
};

void test74()
{
    //std::vector<std::vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    std::vector<std::vector<int>> matrix = { {0} };
    std::cout << std::boolalpha << Solution74::searchMatrix(matrix, 23) << "\n";
}