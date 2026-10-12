// Leetcode 1463
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:

    // Tabulation solution with space optimization
    int solve_with_tabulation_space_optimization(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1 == j2) {
                    front[j1][j2] = grid[n-1][j1];
                } else {
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = -1e9;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            if(j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
                                value += front[j1+dj1][j2+dj2];
                            } else {
                                value += -1e9;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }


    // Tabulation solution
    int solve_with_tabulation(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1 == j2) {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                } else {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = -1e9;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            if(j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
                                value += dp[i+1][j1+dj1][j2+dj2];
                            } else {
                                value += -1e9;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }

    // recursive solution with memoization
    int solve_with_memo(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
            return -1e9;
        }

        if(i == grid.size()-1) {
            if(j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                int value = 0;
                if(j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += solve_with_memo(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    // recursive solution
    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
            return -1e9;
        }

        if(i == grid.size()-1) {
            if(j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                int value = 0;
                if(j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += solve(i+1, j1+dj1, j2+dj2, grid);
                maxi = max(maxi, value);
            }
        }

        return maxi;
    }
   
    int cherryPickup(vector<vector<int>>& grid) {
        
        // return solve(0, 0, grid[0].size()-1, grid);
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        // return solve_with_memo(0, 0, grid[0].size()-1, grid, dp);

        // return solve_with_tabulation(grid);

        return solve_with_tabulation_space_optimization(grid);
    }
};