#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/*
Problem: Shortest Common Supersequence

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
The shortest common supersequence "cabac" has both "abac" and "cab" as subsequences.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
Explanation:
The shortest common supersequence is "aaaaaaaa" since both strings are identical.

*/


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {


        int n = str1.size();
        int m = str2.size();
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
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // characters don't match
                }
            }
        }        

        string ans = "";
        int i = n, j = m;

        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1]; // characters match
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1]; // characters don't match, take character from str1
                i--;
            } else {
                ans += str2[j - 1]; // characters don't match, take character from str2
                j--;
            }
        }

        while(i > 0) {
            ans += str1[i - 1]; // add remaining characters from str1
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1]; // add remaining characters from str2
            j--;
        }

        reverse(ans.begin(), ans.end()); // reverse the answer string to get the correct order

        return ans; // return the shortest common supersequence
    }
};