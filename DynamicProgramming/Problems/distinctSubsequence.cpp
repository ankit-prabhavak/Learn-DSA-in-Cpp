#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
Problem: Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the
characters without disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/


// tabulation solution using 1D dp array single array optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> dp(m + 1, 0); // initialize dp array

        // base case: if t is empty, there is one way to form it
        dp[0] = 1;

        // fill the dp array
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) { // iterate backwards to avoid overwriting values
                if(s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1]; // characters match
                }
                // if characters don't match, dp[j] remains the same
            }
        }

        return dp[m];
    }
};


// tabulation solution using prev and curr arrays
class Solution {
    public:

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0), curr(m + 1, 0); // initialize dp arrays

        // base case: if t is empty, there is one way to form it
        prev[0] = curr[0] =  1;

        // fill the dp arrays
        for(int i = 1; i <= n; i++) {
            curr[0] = 1; // base case for current row
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j]; // characters match
                } else {
                    curr[j] = prev[j]; // characters don't match
                }
            }
            prev = curr; // move to the next row
        }

        return prev[m];
    }
};


// tabulation solution using 2D dp array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0)); // initialize dp table

        // base case: if t is empty, there is one way to form it
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // characters match
                } else {
                    dp[i][j] = dp[i - 1][j]; // characters don't match
                }
            }
        }

        return dp[n][m];
    }
};



// recursive solution with memoization
class Solution {
public:

    int solve(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if(j < 0) return 1; // if t is empty, there is one way to form it
        if(i < 0) return 0; // if s is empty and t is not, there are no ways to form t

        if(dp[i][j] != -1) return dp[i][j]; // return cached result

        if(s[i] == t[j]) {
            // if characters match, we can either include this character or exclude it
            dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
        } else {
            // if characters don't match, we can only exclude this character from s
            dp[i][j] = solve(s, t, i - 1, j, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1)); // initialize memoization table
        return solve(s, t, s.length() - 1, t.length() - 1, dp);
    }
};



// recursive solution
class Solution {
public:

    int solve(string s, string t, int i, int j) {
        if(j < 0) return 1; // if t is empty, there is one way to form it
        if(i < 0) return 0; // if s is empty and t is not, there are no ways to form t

        if(s[i] == t[j]) {
            // if characters match, we can either include this character or exclude it
            return solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
        } else {
            // if characters don't match, we can only exclude this character from s
            return solve(s, t, i - 1, j);
        }
    }

    int numDistinct(string s, string t) {
        return solve(s, t, s.length() - 1, t.length() - 1);
    }
};