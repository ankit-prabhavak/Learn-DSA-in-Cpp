#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    // Tabulation solution with space optimization
    int solve_with_tabulation_space_optimization(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> front(m, 0), curr(m, 0);

        for(int j=0; j<m; j++) {
            front[j] = matrix[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int down = matrix[i][j], leftDiagonal = matrix[i][j], rightDiagonal = matrix[i][j];
                
                down += front[j];

                if(j-1 >= 0) {
                    leftDiagonal += front[j-1];
                } else {
                    leftDiagonal += 1e9;
                }

                if(j+1 < m) {
                    rightDiagonal += front[j+1];
                } else {
                    rightDiagonal += 1e9;
                }

                curr[j] = min(down, min(leftDiagonal, rightDiagonal));
            }
            front = curr;
        }

        int ans = 1e9;
        for(int j=0; j<m; j++) {
            ans = min(ans, front[j]);
        }

        return ans;
    }

    // tabulation solution
    int solve_with_tabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int j=0; j<m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                int down = matrix[i][j], leftDiagonal = matrix[i][j], rightDiagonal = matrix[i][j];
                
                down += dp[i-1][j];

                if(j-1 >= 0) {
                    leftDiagonal += dp[i-1][j-1];
                } else {
                    leftDiagonal += 1e9;
                }

                if(j+1 < m) {
                    rightDiagonal += dp[i-1][j+1];
                } else {
                    rightDiagonal += 1e9;
                }

                dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
            }
        }

        int ans = 1e9;
        for(int j=0; j<m; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
    
    // recursive solution with memoization
    int solve_with_memo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        
        if(j < 0 || j >= matrix[0].size()) {
            return 1e9;
        }

        if(i == 0) {
            return matrix[0][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = matrix[i][j] + solve_with_memo(i-1, j, matrix, dp);
        int leftDiagonal = matrix[i][j] + solve_with_memo(i-1, j-1, matrix, dp);
        int rightDiagonal = matrix[i][j] + solve_with_memo(i-1, j+1, matrix, dp);

        return dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
    }

    // recursive solution
    int solve(int i, int j, vector<vector<int>>& matrix) {
        
        if(j < 0 || j >= matrix[0].size()) {
            return 1e9;
        }

        if(i == 0) {
            return matrix[0][j];
        }

        int down = matrix[i][j] + solve(i-1, j, matrix);
        int leftDiagonal = matrix[i][j] + solve(i-1, j-1, matrix);
        int rightDiagonal = matrix[i][j] + solve(i-1, j+1, matrix);

        return min(down, min(leftDiagonal, rightDiagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 1e9;
        // for(int j=0; j<m; j++) {
        //     ans = min(ans, solve(n-1, j, matrix));
        // }
        

        // for(int j=0; j<m; j++) {
        //     ans = min(ans, solve_with_memo(n-1, j, matrix, dp));
        // }

        // return ans;  
        
        
        // return solve_with_tabulation(matrix);
        return solve_with_tabulation_space_optimization(matrix);
    }
};