#include <bits/stdc++.h>
using namespace std;



/*
Problem: Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rors (delete 'e')
rors -> ros (delete 'r')

*/


// tabulation solution using 1D dp array single array optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // base case: if one of the strings is empty
        for(int j = 0; j <= m; j++) {
            prev[j] = j; // insert all characters of word2
        }

        // fill the dp array
        for(int i = 1; i <= n; i++) {
            curr[0] = i; // delete all characters from word1
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1]; // characters match, no operation needed
                } else {
                    curr[j] = 1 + min({prev[j],    // delete
                                       curr[j - 1], // insert
                                       prev[j - 1]  // replace
                                      });
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
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base case: if one of the strings is empty
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i; // delete all characters from word1
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j; // insert all characters of word2
        }

        // fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],    // delete
                                        dp[i][j - 1],    // insert
                                        dp[i - 1][j - 1] // replace
                                       });
                }
            }
        }

        return dp[n][m];
    }
};

// recursive solution with memoization
class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& memo) {
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]) {
            return memo[i][j] = solve(word1, word2, i - 1, j - 1, memo);
        } else {
            int insertOp = solve(word1, word2, i, j - 1, memo);
            int deleteOp = solve(word1, word2, i - 1, j, memo);
            int replaceOp = solve(word1, word2, i - 1, j - 1, memo);
            return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length(), vector<int>(word2.length(), -1));
        return solve(word1, word2, word1.length() - 1, word2.length() - 1, memo);
    }
};


// recursive solution without memoization
class Solution {
public:
    
    int solve(string word1, string word2, int i, int j) {
        if(i < 0) return j + 1; // if word1 is empty, we need to insert all characters of word2
        if(j < 0) return i + 1; // if word2 is empty, we need to delete all characters of word1

        if(word1[i] == word2[j]) {
            return solve(word1, word2, i - 1, j - 1); // characters match, move to the next pair
        } else {
            // characters don't match, consider all three operations
            int insertOp = solve(word1, word2, i, j - 1); // insert character
            int deleteOp = solve(word1, word2, i - 1, j); // delete character
            int replaceOp = solve(word1, word2, i - 1, j - 1); // replace character
            return 1 + min({insertOp, deleteOp, replaceOp}); // take the minimum of the three operations
        }
    }
    
    int minDistance(string word1, string word2) {
        return solve(word1, word2, word1.length() - 1, word2.length() - 1);
    }
};