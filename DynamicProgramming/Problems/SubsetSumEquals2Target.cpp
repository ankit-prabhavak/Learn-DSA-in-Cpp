#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Problem: Subset Sum Equals 2 Target

Given an array of positive integers arr[] and a value sum, find if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:

1 ≤ arr.size(), arr[i] ≤ 200
1 ≤ sum ≤ 104

*/


class Solution {
  public:

  // Tabulation solution with space optimization
  bool solve_with_tabulation_space_optimization(int n, int sum, vector<int>& arr) {
        vector<bool> prev(sum+1, false), curr(sum+1, false);

        prev[0] = curr[0] = true;

        if(arr[0] <= sum) {
            prev[arr[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if(arr[i] <= j) {
                    take = prev[j-arr[i]];
                }
                curr[j] = take | notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }

   // Tabulation solution
   bool solve_with_tabulation(int n, int sum, vector<int>& arr) {

        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }

        if(arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=sum; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j) {
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take | notTake;
            }
        }

        return dp[n-1][sum];
    }
   
   // recursive solution with memoization
   bool solve_with_memo(int n, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(sum == 0) {
            return true;
        }

        if(n == 0) {
            return arr[0] == sum;
        }

        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }

        bool notTake = solve_with_memo(n-1, sum, arr, dp);
        bool take = false;
        if(arr[n] <= sum) {
            take = solve_with_memo(n-1, sum-arr[n], arr, dp);
        }

        return dp[n][sum] = take | notTake;
    }

   // recursive solution
   bool solve(int n, int sum, vector<int>& arr) {
        if(sum == 0) {
            return true;
        }

        if(n == 0) {
            return arr[0] == sum;
        }

        bool notTake = solve(n-1, sum, arr);
        bool take = false;
        if(arr[n] <= sum) {
            take = solve(n-1, sum-arr[n], arr);
        }

        return take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        // return solve(arr.size() - 1, sum, arr);

        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        return solve_with_memo(arr.size() - 1, sum, arr, dp);

    }
};