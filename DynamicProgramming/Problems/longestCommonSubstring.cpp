#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/*

Problem Statement: Given two strings s1 and s2, find the length of the longest common substring.

Example 1:
Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

Example 2:
Input: s1 = "ABC", s2 = "AC"
Output: 1
Explanation: The longest common substring is "A" which has length 1.

*/


// Approach: Dynamic Programming
class Solution {
  public:

    int solve(string text1, string text2) {

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

        int ans = 0; // variable to store the length of the longest common substring

        // fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match

                    ans = max(ans, dp[i][j]); // update the length of the longest common substring
                } else {
                    dp[i][j] = 0; // characters don't match
                }
            }
        }

        return ans; // return the length of the longest common substring
    }



    int longCommSubstr(string& s1, string& s2) {
        // code here
        return solve(s1, s2);
    }
};