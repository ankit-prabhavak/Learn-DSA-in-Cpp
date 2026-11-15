#include <bits/stdc++.h>
using namespace std;

/*
Problem: Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character. '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false
Explanation: The pattern does not match the entire string.

*/

// tabulation solution using 1D dp array single array optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base case: empty string and empty pattern
        prev[0] = true;

        // Base case: empty string and non-empty pattern
        for (int j = 1; j <= m; j++) {
            prev[j] = (prev[j - 1] && p[j - 1] == '*');
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false;

            for (int j = 1; j <= m; j++) {

                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};


// tabulation solution using 2D dp array
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case: both strings are empty
        dp[0][0] = true;

        // base case: pattern is empty but string is not
        for(int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // base case: string is empty but pattern is not
        for(int j = 1; j <= m; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can match the empty sequence
            } else {
                dp[0][j] = false; // non-* character cannot match the empty string
            }
        }

        // fill the dp array
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match or pattern has '?', move to the next pair
                } else if(p[j - 1] == '*') {
                    // '*' can match zero or more characters
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false; // characters don't match and pattern doesn't have '?' or '*'
                }
            }
        }

        return dp[n][m];
    }
};

// recursive solution with memoization
class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& memo) {
        if(i < 0 && j < 0) return true; // both strings are empty
        if(j < 0 && i >= 0) return false; // pattern is empty but string is not
        if(i < 0 && j >= 0) {
            // string is empty but pattern is not
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false; // if there's any non-* character in the pattern, return false
            }
            return true; // all characters in the pattern are '*', so it matches the empty string
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(p[j] == s[i] || p[j] == '?') {
            return memo[i][j] = solve(s, p, i - 1, j - 1, memo); // characters match or pattern has '?', move to the next pair
        } else if(p[j] == '*') {
            // '*' can match zero or more characters
            return memo[i][j] = solve(s, p, i - 1, j, memo) || solve(s, p, i, j - 1, memo);
        } else {
            return memo[i][j] = false; // characters don't match and pattern doesn't have '?' or '*'
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length(), vector<int>(p.length(), -1));
        return solve(s, p, s.length() - 1, p.length() - 1, memo);
    }
};




// recursive solution
class Solution {
public:
    bool solve(string s, string p, int i, int j) {
        if(i < 0 && j < 0) return true; // both strings are empty
        if(j < 0 && i >= 0) return false; // pattern is empty but string is not
        if(i < 0 && j >= 0) {
            // string is empty but pattern is not
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false; // if there's any non-* character in the pattern, return false
            }
            return true; // all characters in the pattern are '*', so it matches the empty string
        }

        if(p[j] == s[i] || p[j] == '?') {
            return solve(s, p, i - 1, j - 1); // characters match or pattern has '?', move to the next pair
        } else if(p[j] == '*') {
            // '*' can match zero or more characters
            return solve(s, p, i - 1, j) || solve(s, p, i, j - 1);
        } else {
            return false; // characters don't match and pattern doesn't have '?' or '*'
        }
    }
    bool isMatch(string s, string p) {
        return solve(s, p, s.length() - 1, p.length() - 1);
    }
};