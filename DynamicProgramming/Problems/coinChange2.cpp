#include <iostream>
#include <vector>

using namespace std;



/*

Problem: Coin Change 2
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.    

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: There are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: The amount of 3 cannot be made up just with coins of 2.


*/


// tabulation solution with space optimization using previous and current arrays
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<int> prev(amount + 1, 0); 
        vector<int> curr(amount + 1, 0);

        prev[0] = curr[0] = 1; // one way to make up the amount 0

        for(int w=1; w<=amount; w++) {
            if(w % coins[0] == 0) {
                prev[w] = 1; // only one way to make up the amount with the first coin
            }
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=amount; w++) {
                int notTake = prev[w]; // not take the current coin
                int take = 0;
                if(coins[i] <= w) {
                    take = curr[w-coins[i]]; // take the current coin
                }
                curr[w] = take + notTake; // total combinations
            }
            prev = curr;
        }

        return prev[amount]; // return the total combinations for the last coin and the target amount
    }

};

// tabulation solution without space optimization
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int w=0; w<=amount; w++) {
            if(w % coins[0] == 0) {
                dp[0][w] = 1; // only one way to make up the amount with the first coin
            }
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=amount; w++) {
                int notTake = dp[i - 1][w]; // not take the current coin
                int take = 0;
                if(coins[i] <= w) {
                    take = dp[i][w - coins[i]]; // take the current coin
                }
                dp[i][w] = take + notTake; // total combinations
            }
        }

        return dp[n - 1][amount]; // return the total combinations for the last coin and the target amount
    }

};

// memoization solution
class Solution {
public:

     int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {

        if(idx == 0) {
            return (target % coins[0] == 0); // check if the amount can be made up with the first coin
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx - 1, target, coins, dp); // not take the current coin
        int take = 0;
        if(coins[idx] <= target) {
            take = solve(idx, target - coins[idx], coins, dp); // take the current coin
        }

        return dp[idx][target] = take + notTake; // total combinations
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp); // start from the last coin
        
    }

};


// recursive solution
class Solution {
public:
    
    int solve(int idx, int target, vector<int>& coins) {
      
      
        if(idx == 0) {
            return (target % coins[0] == 0); // check if the amount can be made up with the first coin
        }
      
        int notTake = solve(idx - 1, target, coins); // not take the current coin
        int take = 0;
        if(coins[idx] <= target) {
            take = solve(idx, target - coins[idx], coins); // take the current coin
        }

        return take + notTake; // total combinations
    }
     
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        return solve(n - 1, amount, coins); // start from the last coin
        
    }
};