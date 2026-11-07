#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




/*

Problem Statement: Given a string s, find the length of the longest palindromic subsequence in s.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

// Approach: Dynamic Programming
class Solution {
public:
    
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        string rev_s = s; // create a copy of the original string
        reverse(rev_s.begin(), rev_s.end()); // reverse the copy

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // initialize dp table

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == rev_s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // characters don't match
                }
            }
        }

        return dp[n][n]; // return the length of the longest palindromic subsequence
    }
};