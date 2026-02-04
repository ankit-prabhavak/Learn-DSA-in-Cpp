#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// LeetCode Problem 279: Perfect Squares
// Given an integer n, return the least number of perfect square numbers that sum to n.

// Approach 1: Top-Down Dynamic Programming (Memoization)
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(n) for the memoization array and recursion stack



class Solution {
public:
    // Helper function for top-down DP    
    int Solve(int n, vector<int>& dp) {
        if (n <= 0) return 0; // Base case: 0 can be formed with 0 numbers
        if (dp[n] != -1) return dp[n]; // Return already computed result
        
        int minCount = INT_MAX; // Initialize minCount to a large value
        for (int i = 1; i * i <= n; ++i) { // Iterate through all perfect squares <= n
            minCount = min(minCount, 1 + Solve(n - i * i, dp)); // Recursively compute the minimum count
        }
        
        dp[n] = minCount; // Store the computed result in dp array
        return dp[n]; // Return the result for n
    }
       
    int numSquares(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp array with -1
        return Solve(n, dp); // Start the top-down DP process
    }

};
