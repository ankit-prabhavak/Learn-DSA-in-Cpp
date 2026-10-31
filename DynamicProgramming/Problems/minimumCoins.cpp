/*

Problem: Minimum Coins

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
You want to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.


Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

*/

#include <iostream>
#include <vector>

using namespace std;

// tabulation solution with space optimization using previous and current arrays
class Solution {
public:

    int coinChange(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9); 
        vector<int> curr(amount + 1, 1e9);

        for(int w=0; w<=amount; w++) {
            if(w % coins[0] == 0) {
                prev[w] = w / coins[0];
            }
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=amount; w++) {
                int notTake = prev[w];
                int take = 1e9;
                if(coins[i] <= w) {
                    take = 1 + curr[w-coins[i]];
                }
                curr[w] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};


// tabulation solution without space optimization
class Solution {
public:

    int coinChange(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for(int w=0; w<=amount; w++) {
            if(w % coins[0] == 0) {
                dp[0][w] = w / coins[0];
            }
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=amount; w++) {
                int notTake = dp[i-1][w];
                int take = 1e9;
                if(coins[i] <= w) {
                    take = 1 + dp[i][w-coins[i]];
                }
                dp[i][w] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};



// memoization solution
class Solution {
public: 

      int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {

        if(idx == 0) {
            if (target % coins[0] == 0) {
                return target / coins[0];
            } else {
                return 1e9; // Return a large number to indicate it's not possible
            }
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx - 1, target, coins, dp);
        int take = 1e9;

        if(coins[idx] <= target) {
            take = 1 + solve(idx, target - coins[idx], coins, dp);
        }

        return dp[idx][target] = min(take, notTake);

      }
      
      int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
        
      }
};


// recursive solution
class Solution {
public:

    int solve(int idx, int target, vector<int>& coins) {

        if(idx == 0) {
            if (target % coins[0] == 0) {
                return target / coins[0];
            } else {
                return 1e9; // Return a large number to indicate it's not possible
            }
        }

        int notTake = solve(idx - 1, target, coins);
        int take = 1e9;

        if(coins[idx] <= target) {
            take = 1 + solve(idx, target - coins[idx], coins);
        }

        return min(take, notTake);
    } 


    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int ans = solve(n - 1, amount, coins);
        return (ans >= 1e9) ? -1 : ans;
    }
};