#include<iostream>
#include<vector>
#include<climits>
using namespace std;



/*

Problem: Rod Cutting
You are given a rod of length n and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces. You can cut the rod in any number of pieces and in any order.
You can also choose not to cut the rod at all.

Example 1:
Input: n = 8, prices = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22

Explanation: The maximum value can be obtained by cutting the rod into two pieces of length 2 and 6, which gives a total value of 5 + 17 = 22.

Example 2:
Input: n = 5, prices = [2, 5, 7, 8, 10]
Output: 12

Explanation: The maximum value can be obtained by cutting the rod into two pieces of length 2 and 3, which gives a total value of 5 + 7 = 12.

*/


// tabulation with space optimization using 1D array
class Solution {
public:

    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n + 1, 0);

        for(int len=0; len<=n; len++) {
            dp[len] = len * price[0]; // take as many of the first piece as possible
        }

        for(int idx=1; idx<n; idx++) {
            for(int len=0; len<=n; len++) {
                int notTake = dp[len]; // not take the current piece
                int take = INT_MIN;

                if(idx + 1 <= len) {
                    take = price[idx] + dp[len - (idx + 1)]; // take the current piece
                }

                dp[len] = max(take, notTake); // return the maximum value
            }
        }

        return dp[n]; // return the maximum value for the last piece and the target length

    }
};

// tabulation with space optimization using previous and current arrays
class Solution {
public:

    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int len=0; len<=n; len++) {
            prev[len] = len * price[0]; // take as many of the first piece as possible
        }

        for(int idx=1; idx<n; idx++) {
            for(int len=0; len<=n; len++) {
                int notTake = prev[len]; // not take the current piece
                int take = INT_MIN;

                if(idx + 1 <= len) {
                    take = price[idx] + curr[len - (idx + 1)]; // take the current piece
                }

                curr[len] = max(take, notTake); // return the maximum value
            }
            prev = curr;
        }

        return prev[n]; // return the maximum value for the last piece and the target length

    }
};


// tabulation without space optimization
class Solution {
public:

    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for(int i=0; i<=n; i++) {
            dp[0][i] = i * price[0]; // take as many of the first piece as possible
        }

        for(int idx=1; idx<n; idx++) {
            for(int len=0; len<=n; len++) {
                int notTake = dp[idx - 1][len]; // not take the current piece
                int take = INT_MIN;

                if(idx + 1 <= len) {
                    take = price[idx] + dp[idx][len - (idx + 1)]; // take the current piece
                }

                dp[idx][len] = max(take, notTake); // return the maximum value
            }
        }

        return dp[n - 1][n]; // return the maximum value for the last piece and the target length

    }
};


// recursive solution with memoization
class Solution {
    public:
    
        int solve(int idx, int n, vector<int>& price, vector<vector<int>>& dp) {
    
            if(idx == 0) {
                return n * price[0]; // take as many of the first piece as possible
            }
    
            if(dp[idx][n] != -1) return dp[idx][n];
    
            int notTake = solve(idx - 1, n, price, dp); // not take the current piece
            int take = INT_MIN;
    
            if(idx + 1 <= n) {
                take = price[idx] + solve(idx, n - (idx + 1), price, dp); // take the current piece
            }
    
            return dp[idx][n] = max(take, notTake); // return the maximum value
    
        }
        int cutRod(vector<int> &price) {
            // code here
            int n = price.size();
            vector<vector<int>> dp(n, vector<int>(n + 1, -1));
            return solve(n - 1, n, price, dp);
        }
};



// recursive solution
class Solution {
  public:

    int solve(int idx, int n, vector<int>& price) {

        if(idx == 0) {
            return n * price[0]; // take as many of the first piece as possible
        }

        int notTake = solve(idx - 1, n, price); // not take the current piece
        int take = INT_MIN;

        if(idx + 1 <= n) {
            take = price[idx] + solve(idx, n - (idx + 1), price); // take the current piece
        }

        return max(take, notTake); // return the maximum value

    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        return solve(n - 1, n, price);
    }
};