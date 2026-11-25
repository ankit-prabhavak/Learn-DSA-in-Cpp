#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

         int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int index = n - 1; index >= 0; index--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy) {
                    // Option to buy or skip
                    dp[index][canBuy] = max(-prices[index] - fee + dp[index + 1][0], dp[index + 1][1]);
                } else {
                    // Option to sell or skip
                    dp[index][canBuy] = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
        
    }
};