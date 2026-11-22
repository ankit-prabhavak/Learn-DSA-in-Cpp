#include <iostream>
#include <vector>
using namespace std;


/*
Problem: Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions.

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

*/


// tabulation solution with space optimization using previous and current arrays
class Solution {
public:
 
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2 * k + 1, 0);
        vector<int> curr(2 * k + 1, 0);

        for(int index = n - 1; index >= 0; index--) {
            for(int transactionsLeft = 1; transactionsLeft <= 2 * k; transactionsLeft++) {
                if(transactionsLeft % 2 == 0) {
                    // Option to buy or skip
                    curr[transactionsLeft] = max(-prices[index] + after[transactionsLeft - 1], 
                                                  after[transactionsLeft]);
                } else {
                    // Option to sell or skip
                    curr[transactionsLeft] = max(prices[index] + after[transactionsLeft - 1], 
                                                          after[transactionsLeft]);
                }
            }
            after = curr;
        }

        return after[2 * k];
    }
};


// tabulation solution
class Solution {
public: 
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for(int index = n - 1; index >= 0; index--) {
           
                for(int transactionsLeft = 1; transactionsLeft <= 2 * k; transactionsLeft++) {
                    if(transactionsLeft % 2 == 0) {
                        // Option to buy or skip
                        dp[index][transactionsLeft] = max(-prices[index] + dp[index + 1][transactionsLeft - 1], 
                                                          dp[index + 1][transactionsLeft]);
                    } else {
                        // Option to sell or skip
                        dp[index][transactionsLeft] = max(prices[index] + dp[index + 1][transactionsLeft - 1], 
                                                          dp[index + 1][transactionsLeft]);
                    }
                }
            
        }

        return dp[0][2 * k];
    }
 
};


// recursive solution with n x 2 * k  array space optimization
class Solution {
    public:
    int solve(vector<int>& prices, int index, int transactionsLeft, vector<vector<int>>& memo) {
        if(index >= prices.size() || transactionsLeft == 0) return 0;

        if(memo[index][transactionsLeft] != -1) return memo[index][transactionsLeft];

        if(transactionsLeft % 2 == 0) {
            // Option to buy or skip
            memo[index][transactionsLeft] = max(-prices[index] + solve(prices, index + 1, transactionsLeft - 1, memo), 
                                                solve(prices, index + 1, transactionsLeft, memo));
        } else {
            // Option to sell or skip
            memo[index][transactionsLeft] = max(prices[index] + solve(prices, index + 1, transactionsLeft - 1, memo), 
                                                solve(prices, index + 1, transactionsLeft, memo));
        }

        return memo[index][transactionsLeft];

    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2 * k + 1, -1));
        return solve(prices, 0, 2 * k, memo);
    }
};



// resursive solution without memoization
class Solution {
public:

    int solve(vector<int>& prices, int index, int transactionsLeft) {
        if(index >= prices.size() || transactionsLeft == 0) return 0;

        if(transactionsLeft % 2 == 0) {
            // Option to buy or skip
            return max(-prices[index] + solve(prices, index + 1, transactionsLeft - 1), 
                        solve(prices, index + 1, transactionsLeft));
        } else {
            // Option to sell or skip
            return max(prices[index] + solve(prices, index + 1, transactionsLeft - 1), 
                        solve(prices, index + 1, transactionsLeft));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        
        return solve(prices, 0, 2 * k);
    }
};