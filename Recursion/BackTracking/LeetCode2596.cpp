#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int n, int expVal) {
        // Check if the current position is out of bounds or does not match the expected value
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expVal) {
            return false;
        }

        // If the expected value is the last value in the grid, return true
        if (expVal == n * n - 1) {
            return true;
        }

        // Explore all possible knight moves
        bool move1 = isValid(grid, row - 2, col + 1, n, expVal + 1);
        bool move2 = isValid(grid, row - 1, col + 2, n, expVal + 1);
        bool move3 = isValid(grid, row + 1, col + 2, n, expVal + 1);
        bool move4 = isValid(grid, row + 2, col + 1, n, expVal + 1);
        bool move5 = isValid(grid, row + 2, col - 1, n, expVal + 1);
        bool move6 = isValid(grid, row + 1, col - 2, n, expVal + 1);
        bool move7 = isValid(grid, row - 1, col - 2, n, expVal + 1);
        bool move8 = isValid(grid, row - 2, col - 1, n, expVal + 1);

        // Return true if any of the moves lead to a valid path
        return move1 || move2 || move3 || move4 || move5 || move6 || move7 || move8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        // Start the validation from the top-left corner (0, 0) with the expected value 0
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    Solution s;

    // Test case: A valid knight's tour grid
    vector<vector<int>> grid = {
        {0, 17, 8, 25, 2},
        {9, 24, 1, 16, 7},
        {18, 11, 20, 3, 26},
        {23, 10, 15, 6, 19},
        {12, 21, 4, 27, 14}
    };

    if (s.checkValidGrid(grid)) {
        cout << "The grid represents a valid knight's tour." << endl;
    } else {
        cout << "The grid does not represent a valid knight's tour." << endl;
    }

    return 0;
}