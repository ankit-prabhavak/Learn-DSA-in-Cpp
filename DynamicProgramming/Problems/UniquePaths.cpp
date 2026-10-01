#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Tabulation solution with space optimization
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else {
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


    // Tabulation solution
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m-1][n-1];
    }

    int solve(int m, int n, vector<vector<int>>& dp) {
        if(m == 0 && n == 0) return 1;

        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int left = solve(m-1, n, dp);
        int up = solve(m, n-1, dp);

        return dp[m][n] = left + up;
    }
    
    // DP solution with memoization
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }


    // recursive solution
    int uniquePaths(int m, int n) {
        return solve(m - 1, n - 1);
    }

    int solve(int m, int n) {
        if (m == 0 && n == 0)
            return 1;

        if (m < 0 || n < 0)
            return 0;

        return solve(m - 1, n) + solve(m, n - 1);
    }
};
    