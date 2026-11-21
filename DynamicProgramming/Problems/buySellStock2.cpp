#include <iostream>
#include <vector>
using namespace std;


/*
Problem: Best Time to Buy and Sell Stock II
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.

*/



// tabulation solution
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int index = n - 1; index >= 0; index--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy) {
                    // Option to buy or skip
                    dp[index][canBuy] = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                } else {
                    // Option to sell or skip
                    dp[index][canBuy] = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};


// recursive solution with memoization
class Solution {
public:

      int solve(vector<int>& prices, int index, bool canBuy, vector<vector<int>>& memo) {
        if(index >= prices.size()) return 0;

        if(memo[index][canBuy] != -1) return memo[index][canBuy];

        int profit = 0;
        if(canBuy) {
            // Option to buy or skip
            profit = max(-prices[index] + solve(prices, index + 1, false, memo), solve(prices, index + 1, true, memo));
        } else {
            // Option to sell or skip
            profit = max(prices[index] + solve(prices, index + 1, true, memo), solve(prices, index + 1, false, memo));
        }
        return memo[index][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, true, memo);
    }
};

// recursive solution
class Solution {
public:

    int solve(vector<int>& prices, int index, bool canBuy) {
        if(index >= prices.size()) return 0;

        int profit = 0;
        if(canBuy) {
            // Option to buy or skip
            profit = max(-prices[index] + solve(prices, index + 1, false), solve(prices, index + 1, true));
        } else {
            // Option to sell or skip
            profit = max(prices[index] + solve(prices, index + 1, true), solve(prices, index + 1, false));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        
        return solve(prices, 0, true);
        
    }
};