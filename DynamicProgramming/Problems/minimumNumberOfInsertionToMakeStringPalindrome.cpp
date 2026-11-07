/*

Problem: Minimum Number of Insertion to Make String Palindrome

Given a string s, return the minimum number of characters that we need to insert to make s a palindrome.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already a palindrome.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: The minimum insertions needed to make "mbadm" a palindrome is 2,
    either "mbdadbm" or "mdbabdm".


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

    int minInsertions(string s) {

        return s.size() - longestPalindromeSubseq(s);
        
    }
};