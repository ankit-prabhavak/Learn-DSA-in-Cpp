#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Tabulation solution with space optimization
    int minimumTotalTabulationWithSpaceOptimization(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0), curr(n, 0);

        for(int j=0; j<n; j++) {
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];

                curr[j] = min(down, diagonal);
            }
            front = curr;
        }

        return front[0];
    }

    // Tabulation solution
    int minimumTotalTabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
    
    // recursive solution with memoization
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = triangle[i][j] + solve(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + solve(i+1, j+1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    // recursive solution
    int solve(int i, int j, vector<vector<int>>& triangle) {
        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }

        int down = triangle[i][j] + solve(i+1, j, triangle);
        int diagonal = triangle[i][j] + solve(i+1, j+1, triangle);

        return min(down, diagonal);
    } 


    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(0, 0, triangle);

        // return minimumTotalTabulation(triangle);

        // return minimumTotalTabulationWithSpaceOptimization(triangle);

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};