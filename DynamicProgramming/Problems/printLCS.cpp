#include <iostream>
#include <vector>
#include <string>

using namespace std;

// tabulation approach to find the longest common subsequence and print it
class Solution {
public:
      
    void longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // initialize dp table

        // base case: if either string is empty, the LCS length is 0
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        // fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // characters don't match
                }
            }
        }
         
        int idx = dp[n][m]; // length of the longest common subsequence
        string lcs = "";

        for(int i = 0; i < idx; i++) {
            lcs += '$'; // initialize lcs string with placeholder characters
        }

        int i = n, j = m;
        while(i > 0 && j > 0) {

            if(text1[i - 1] == text2[j - 1]) {
                lcs[idx - 1] = text1[i - 1]; // add character to lcs
                i--;
                j--;
                idx--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                i--; // move up in the dp table
            } else {
                j--; // move left in the dp table
            }
        }

        cout << "Longest Common Subsequence: " << lcs << endl; // print the longest common subsequence
    }
};