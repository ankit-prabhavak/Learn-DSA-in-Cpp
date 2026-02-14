#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Leetcode 73: Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Sets to store rows and columns that need to be zeroed
        set<int> rows_to_zero;
        set<int> cols_to_zero;

        // First pass: find all rows and columns that contain 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows_to_zero.insert(i);
                    cols_to_zero.insert(j);
                }
            }
        }

        // Second pass: set elements to 0 if their row or column is marked
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows_to_zero.count(i) || cols_to_zero.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};