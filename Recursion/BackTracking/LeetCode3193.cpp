#include <vector>
#include <iostream>
using namespace std;


// LeetCode 3193: Number of Permutations With Inversion Count
// Approach: Dynamic Programming

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        for (auto &r : requirements) {
            req[r[0]] = r[1];
        }

        int maxInv = 400;

        vector<vector<int>> dp(n + 1, vector<int>(maxInv + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> prefix(maxInv + 1, 0);

            // prefix sum of dp[i-1]
            prefix[0] = dp[i - 1][0];
            for (int j = 1; j <= maxInv; j++) {
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;
            }

            for (int k = 0; k <= maxInv; k++) {
                int val = prefix[k];
                if (k - i >= 0) {
                    val = (val - prefix[k - i] + MOD) % MOD;
                }
                dp[i][k] = val;
            }

            // enforce requirement if exists
            if (req[i - 1] != -1) {
                int required = req[i - 1];
                for (int k = 0; k <= maxInv; k++) {
                    if (k != required) dp[i][k] = 0;
                }
            }
        }

        int result = 0;
        for (int k = 0; k <= maxInv; k++) {
            result = (result + dp[n][k]) % MOD;
        }

        return result;
    }
};