#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*

Problem: Minimum Insertion/Deletion to Make Strings Equal

Given two strings word1 and word2, return the minimum number of operations required to make them equal.
In each operation, you can insert or delete a character from either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need 1 operation to delete 's' from "sea" and 1 operation to insert 't' into "sea" to get "eat".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4
Explanation: You need 4 operations to make the strings equal.

*/


// Approach: Dynamic Programming
class Solution {
public:

    int longestPalindromeSubseq(string s, string t) {

        int n = s.size();
        int m = t.size();
        

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // initialize dp table

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // characters don't match
                }
            }
        }

        return dp[n][n]; // return the length of the longest palindromic subsequence
    }

    int canYouMake(string s, string t) {

        int n = s.size();
        int m = t.size();

        int lcsLength = longestPalindromeSubseq(s, t); // find the length of the longest common subsequence

        return n + m - 2 * lcsLength; // return the minimum number of operations required to make the strings equal
        
    }
};