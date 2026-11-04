#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*

Problem: Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted 
without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:
Input: text1 = "abcde", text2 = "ace"
Output: 3

Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3

Explanation: The longest common subsequence is "abc" and its length is 3.

*/

// tabulation with space optimization using previous and current arrays
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0); // initialize previous and current arrays

        // base case: if either string is empty, the LCS length is 0
        for(int j = 0; j <= m; j++) {
            prev[j] = 0;
        }

        // fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1]; // characters match
                } else {
                    curr[j] = max(prev[j], curr[j - 1]); // characters don't match
                }
            }
            prev = curr; // update previous array for next iteration
        }

        return prev[m]; // return the length of the longest common subsequence
        
    }
};



// tabulation without space optimization
class Solution {
public:
      
    int longestCommonSubsequence(string text1, string text2) {

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

        return dp[n][m]; // return the length of the longest common subsequence
    }
};



// recursive solution with memoization
class Solution {
public:
      
    int solve(int idx1, int idx2, string &text1, string &text2, vector<vector<int>>& dp) {
        if(idx1 < 0 || idx2 < 0) return 0; // base case

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2]; // check if already computed

        if(text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, text1, text2, dp); // characters match
        } else {
            return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, text1, text2, dp), solve(idx1, idx2 - 1, text1, text2, dp)); // characters don't match
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // initialize memoization table
        return solve(n - 1, m - 1, text1, text2, dp); // call the recursive function
        
    }
};



// recursive solution
class Solution {
public:
    
    int solve(int idx1, int idx2, string &text1, string &text2) {
        if(idx1 < 0 || idx2 < 0) return 0; // base case

        if(text1[idx1] == text2[idx2]) {
            return 1 + solve(idx1 - 1, idx2 - 1, text1, text2); // characters match
        } else {
            return max(solve(idx1 - 1, idx2, text1, text2), solve(idx1, idx2 - 1, text1, text2)); // characters don't match
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
        return solve(n - 1, m - 1, text1, text2); // call the recursive function
        
    }
};