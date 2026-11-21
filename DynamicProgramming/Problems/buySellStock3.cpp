#include <iostream>
#include <vector>
using namespace std;


/*
Problem: Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing at most two transactions. 
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.

*/





// resursive solution with n x 4  array space optimization
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


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(5, -1));
        return solve(prices, 0, 4, memo);
    }
};


// tabulation solution with space optimization using previous and current arrays
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<vector<int>> after(2, vector<int>(3, 0));
         vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int index = n - 1; index >= 0; index--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                for(int transactionsLeft = 1; transactionsLeft <= 2; transactionsLeft++) {
                    if(canBuy) {
                        // Option to buy or skip
                        curr[canBuy][transactionsLeft] = max(-prices[index] + after[0][transactionsLeft], 
                                                                  after[1][transactionsLeft]);
                    } else {
                        // Option to sell or skip
                        curr[canBuy][transactionsLeft] = max(prices[index] + after[1][transactionsLeft - 1], 
                                                                  after[0][transactionsLeft]);
                    }
                }
            }

            after = curr;
        }

        return after[1][2];
    }
};



// tabulation solution
class Solution {
public:
       
       int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index = n - 1; index >= 0; index--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                for(int transactionsLeft = 1; transactionsLeft <= 2; transactionsLeft++) {
                    if(canBuy) {
                        // Option to buy or skip
                        dp[index][canBuy][transactionsLeft] = max(-prices[index] + dp[index + 1][0][transactionsLeft], 
                                                                  dp[index + 1][1][transactionsLeft]);
                    } else {
                        // Option to sell or skip
                        dp[index][canBuy][transactionsLeft] = max(prices[index] + dp[index + 1][1][transactionsLeft - 1], 
                                                                  dp[index + 1][0][transactionsLeft]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};



// recursive solution with memoization
class Solution {
    int solve(vector<int>& prices, int index, bool canBuy, int transactionsLeft, vector<vector<vector<int>>>& memo) {
        if(index >= prices.size() || transactionsLeft == 0) return 0;

        if(memo[index][canBuy][transactionsLeft] != -1) return memo[index][canBuy][transactionsLeft];

        if(canBuy) {
            // Option to buy or skip
            memo[index][canBuy][transactionsLeft] = max(-prices[index] + solve(prices, index + 1, false, transactionsLeft, memo), 
                                                        solve(prices, index + 1, true, transactionsLeft, memo));
        } else {
            // Option to sell or skip
            memo[index][canBuy][transactionsLeft] = max(prices[index] + solve(prices, index + 1, true, transactionsLeft - 1, memo), 
                                                        solve(prices, index + 1, false, transactionsLeft, memo));
        }

        return memo[index][canBuy][transactionsLeft];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, true, 2, memo);
    }
};


// recursive solution
class Solution {
public:
    
    int solve(vector<int>& prices, int index, bool canBuy, int transactionsLeft) {
        if(index >= prices.size() || transactionsLeft == 0) return 0;

        if(canBuy) {
            // Option to buy or skip
            return max(-prices[index] + solve(prices, index + 1, false, transactionsLeft), 
                       solve(prices, index + 1, true, transactionsLeft));
        } else {
            // Option to sell or skip
            return max(prices[index] + solve(prices, index + 1, true, transactionsLeft - 1), 
                       solve(prices, index + 1, false, transactionsLeft));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, true, 2);
    }
};