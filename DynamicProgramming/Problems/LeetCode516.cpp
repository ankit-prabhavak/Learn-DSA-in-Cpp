#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {

        if (text1.size() < text2.size())
            swap(text1, text2);

        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m + 1);

        for (int i = 1; i <= n; i++) {
            int prevDiagonal = 0;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (text1[i - 1] == text2[j - 1])
                    dp[j] = prevDiagonal + 1;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prevDiagonal = temp;
            }
        }

        return dp[m];
    }

    int longestPalindromeSubseq(string s) {

        string ss = s;
        reverse(ss.begin(), ss.end());
        
        return longestCommonSubsequence(s, ss);
    }
};