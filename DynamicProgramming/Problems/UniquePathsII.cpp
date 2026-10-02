#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    // Tabulation solution with space optimization
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if(i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int left = 0, up = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];

                    curr[j] = left + up;
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }

    // Tabulation solution with recursion stack space optimization
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = left + up;
                }
            }
        }   

        return dp[m-1][n-1];

    }
        

    // Recursive solution with memoization
    int solve(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if(m == 0 && n == 0) return 1;

        if(m < 0 || n < 0) return 0;

        if(obstacleGrid[m][n] == 1) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int left = solve(m-1, n, dp, obstacleGrid);
        int up = solve(m, n-1, dp, obstacleGrid);

        return dp[m][n] = left + up;
    }

      
    // Recursive solution
    int solve(int m, int n, vector<vector<int>>& obstacleGrid) {
        if(m == 0 && n == 0) return 1;

        if(m < 0 || n < 0) return 0;

        if(obstacleGrid[m][n] == 1) return 0;

        int left = solve(m-1, n, obstacleGrid);
        int up = solve(m, n-1, obstacleGrid);

        return left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // return solve(m-1, n-1, obstacleGrid);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, dp, obstacleGrid);
    }
};