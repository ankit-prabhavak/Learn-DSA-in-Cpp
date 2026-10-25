#include <iostream>
#include <vector>
using namespace std;


// Problem: Count of subsets with sum K
// Given an array of positive integers and a sum K, we need to find the count of subsets of the given array with sum equal to K.


// Important Note:
// If the array contains negative numbers, we can use the same approach but a different data structure to store the count of subsets with sum K. 
// We can use a hash map to store the count of subsets with sum K for each index of the array. 
// The key of the hash map will be the sum and the value will be the count of subsets with that sum.
// We can use a recursive function to find the count of subsets with sum K for each index of the array and store it in the hash map. 
// Finally, we can return the count of subsets with sum K from the hash map.


class Solution {

    // tabulation with space optimization
    int solveTabulationSpaceOptimized(vector<int> &num, int tar) {
        
        int n = num.size();
        vector<int> prev(tar+1, 0), curr(tar+1, 0);

        prev[0] = curr[0] = 1;

        if(num[0] <= tar) {
            prev[num[0]] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=tar; j++) {
                int notTake = prev[j];
                int take = 0;
                if(num[i] <= j) {
                    take = prev[j-num[i]];
                }
                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[tar];
    }

    // tabulation without space optimization
    int solveTabulation(vector<int> &num, int tar) {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, 0));

        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }

        if(num[0] <= tar) {
            dp[0][num[0]] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=tar; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if(num[i] <= j) {
                    take = dp[i-1][j-num[i]];
                }
                dp[i][j] = take + notTake;
            }
        }

        return dp[n-1][tar];
    }

    // memoization solution
    int solve(int index, int target, vector<int> &num, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(index == 0) return num[0] == target;

        if(dp[index][target] != -1) return dp[index][target];

        int notTake = solve(index-1, target, num, dp);
        int take = 0;
        if(num[index] <= target) {
            take = solve(index-1, target-num[index], num, dp);
        }

        return dp[index][target] = take + notTake;
    }


    // recursive solution
    int solve(int index, int target, vector<int> &num) {
        if(target == 0) return 1;
        if(index == 0) return num[0] == target;

        int notTake = solve(index-1, target, num);
        int take = 0;
        if(num[index] <= target) {
            take = solve(index-1, target-num[index], num);
        }

        return take + notTake;
    }

    int findWays(vector<int> &num, int tar) {

        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(n-1, tar, num, dp);
       
    }
};



