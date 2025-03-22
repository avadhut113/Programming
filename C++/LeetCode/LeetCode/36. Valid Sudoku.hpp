#pragma once
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution36 {
public:
    int coord2gridIdx(int i, int j) {
        /*
        grid 0: i: [0-2], j:[0-2]
        grid 1: i: [0-2], j:[3-5]
        grid 2: i: [0-2], j:[6-8]
        */

        return i / 3 * 3 + j / 3;
    };

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), grids(9);
        pair<set<char>::iterator, bool> ret;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int gridIdx = coord2gridIdx(i, j);
                ret = rows[i].insert(c);
                if (!ret.second) 
                    return false;
                ret = cols[j].insert(c);
                if (!ret.second) 
                    return false;
                ret = grids[gridIdx].insert(c);
                if (!ret.second) 
                    return false;
            }
        }

        return true;
    }
};

void test36()
{
    //vector<vector<char>> sudoku = { {'5','3','.','.','7','.','.','.','.'}
    //                                ,{'6','.','.','1','9','5','.','.','.'}
    //                                ,{'.','9','8','.','.','.','.','6','.'}
    //                                ,{'8','.','.','.','6','.','.','.','3'}
    //                                ,{'4','.','.','8','.','3','.','.','1'}
    //                                ,{'7','.','.','.','2','.','.','.','6'}
    //                                ,{'.','6','.','.','.','.','2','8','.'}
    //                                ,{'.','.','.','4','1','9','.','.','5'}
    //                                ,{'.','.','.','.','8','.','.','7','9'} };

    vector<vector<char>> sudoku = { {'8','3','.','.','7','.','.','.','.'}
                                    ,{'6','.','.','1','9','5','.','.','.'}
                                    ,{'.','9','1','.','.','.','.','6','.'}
                                    ,{'8','.','.','.','6','.','.','.','3'}
                                    ,{'4','.','.','8','.','3','.','.','1'}
                                    ,{'7','.','.','.','2','.','.','.','6'}
                                    ,{'.','6','.','.','.','.','2','8','.'}
                                    ,{'.','.','.','4','1','9','.','.','5'}
                                    ,{'.','.','.','.','8','.','.','7','9'} };

    Solution36 sl36;
    std::cout << std::boolalpha << sl36.isValidSudoku(sudoku) << "\n";
}