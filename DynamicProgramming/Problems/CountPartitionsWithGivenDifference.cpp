#include <iostream>
#include <vector>
using namespace std;

// Count Partitions With Given Difference

/*
Problem: Count Partitions With Given Difference
Given an array of positive integers and a difference D, we need to find the count of partitions of 
the given array into two subsets such that the difference of the sum of elements in the two subsets is equal to D.

Since the answer can be very large, return the answer modulo 10^9 + 7.

*/


class Solution {
        
    int mod = 1e9 + 7; // modulo value

    // tabulation with space optimization
    int solveTabulationSpaceOptimized(vector<int> &num, int tar) {
        
        int n = num.size();
        vector<int> prev(tar+1, 0), curr(tar+1, 0);

        // prev[0] = curr[0] = 1;

        // if(num[0] <= tar) {
        //     prev[num[0]] = 1;
        // }


        if(num[0] == 0) {
            prev[0] = 2; // two ways: include or exclude the zero
        } else {
            prev[0] = 1; // one way: exclude the first element
        }

        if(num[0] != 0 && num[0] <= tar) {
            prev[num[0]] = 1; // one way: include the first element
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=tar; j++) {
                int notTake = prev[j];
                int take = 0;
                if(num[i] <= j) {
                    take = prev[j-num[i]];
                }
                curr[j] = (take + notTake) % mod;
            }
            prev = curr;
        }

        return prev[tar];
    }

    // tabulation without space optimization
    int solveTabulation(vector<int> &num, int tar) {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));

        // for(int i=0; i<n; i++) {
        //     dp[i][0] = 1;
        // }

        // if(num[0] <= tar) {
        //     dp[0][num[0]] = 1;
        // }

        if(num[0] == 0) {
            dp[0][0] = 2; // two ways: include or exclude the zero
        } else {
            dp[0][0] = 1; // one way: exclude the first element
        }

        if(num[0] != 0 && num[0] <= tar) {
            dp[0][num[0]] = 1; // one way: include the first element
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=tar; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if(num[i] <= j) {
                    take = dp[i-1][j-num[i]];
                }
                dp[i][j] = (take + notTake) % mod;
            }
        }

        return dp[n-1][tar];
    }

    // memoization solution
    int solve(int index, int target, vector<int> &num, vector<vector<int>> &dp) {
        // if(target == 0) return 1;
        // if(index == 0) return num[0] == target;

        if(index == 0) {
            if(target == 0 && num[0] == 0) return 2; // two ways: include or exclude the zero
            if(target == 0 || target == num[0]) return 1; // one way: either include or exclude
            return 0; // no way
        }

        if(dp[index][target] != -1) return dp[index][target];

        int notTake = solve(index-1, target, num, dp);
        int take = 0;
        if(num[index] <= target) {
            take = solve(index-1, target-num[index], num, dp);
        }

        return dp[index][target] = (take + notTake) % mod;
    }


    // recursive solution
    int solve(int index, int target, vector<int> &num) {

        if(index == 0) {
            if(target == 0 && num[0] == 0) return 2; // two ways: include or exclude the zero
            if(target == 0 || target == num[0]) return 1; // one way: either include or exclude
            return 0; // no way
        }

        int notTake = solve(index-1, target, num);
        int take = 0;
        if(num[index] <= target) {
            take = solve(index-1, target-num[index], num);
        }

        return (take + notTake) % mod;
    }

    int findWays(vector<int> &num, int tar) {

        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(n-1, tar, num, dp);
       
    }


    int countPartitions(int n, int d, vector<int> &arr) {

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }

        if(sum - d < 0 || (sum - d) % 2 != 0) {
            return 0;
        }

        int target = (sum - d) / 2;

        return findWays(arr, target);
        
    }
};