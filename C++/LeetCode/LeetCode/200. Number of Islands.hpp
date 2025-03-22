#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution200 {
public:
    // Function to count the number of islands in a given grid
    static int numIslands(vector<vector<char>>& grid) {
        int rowCount = grid.size();      // Number of rows in the grid
        int colCount = grid[0].size();   // Number of columns in the grid
        int islandCount = 0;             // Number of islands found

        // Directions array for moving up, right, down, left
        int directions[5] = { -1, 0, 1, 0, -1 };

        // Depth-First Search (DFS) to traverse the island and mark visited parts
        function<void(int, int)> dfs = [&](int row, int col) {
            grid[row][col] = '0'; // Mark the current cell as visited
            // Traverse adjacent cells
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
                // Check if the new position is within bounds and has a '1' (unvisited land)
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 && newCol < colCount && grid[newRow][newCol] == '1') {
                    dfs(newRow, newCol); // Recursively call DFS for the adjacent cell
                }
            }
            };

        // Iterate through the entire grid
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                // If the cell contains a '1', it is a new island
                if (grid[row][col] == '1') {
                    dfs(row, col);     // Perform DFS to mark all connected lands
                    islandCount++;     // Increment island count
                }
            }
        }
        return islandCount; // Return the total count of islands
    }
};

void test200()
{
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

    std::cout << Solution200::numIslands(grid);
}