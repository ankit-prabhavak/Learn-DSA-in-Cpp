#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*

Problem: Unbounded Knapsack
You are given an integer array weights representing the weights of different items and an integer array values representing
the values of the items. You are also given an integer capacity representing the maximum weight that can be carried.
Return the maximum value that can be obtained by selecting items such that the total weight does not exceed
the capacity. You can select an item multiple times.

Example 1:
Input: weights = [1, 2, 3], values = [10, 15, 40], capacity = 6
Output: 80

Explanation: The maximum value can be obtained by selecting the item with weight 3 and value 40 twice.

Example 2:
Input: weights = [1, 3, 4], values = [10, 40, 50], capacity = 6
Output: 80
Explanation: The maximum value can be obtained by selecting the item with weight 3 and value 40 once and the item with weight 1 and value 10 twice.


*/


// tabulation with space optimization using 1D array
class Solution {
public:

    int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {

        int n = weights.size();
        vector<int> dp(capacity + 1, 0);

        for(int w=0; w<=capacity; w++) {
            dp[w] = (w / weights[0]) * values[0]; // take as many of the first item as possible
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=capacity; w++) {
                int notTake = dp[w]; // not take the current item
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + dp[w - weights[i]]; // take the current item
                }
                dp[w] = max(take, notTake); // return the maximum value
            }
        }

        return dp[capacity]; // return the maximum value for the last item and the target capacity

    }

};




// tabulation with space optimization
class Solution {
public:

    int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {

        int n = weights.size();
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);

        for(int w=0; w<=capacity; w++) {
            prev[w] = (w / weights[0]) * values[0]; // take as many of the first item as possible
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=capacity; w++) {
                int notTake = prev[w]; // not take the current item
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + curr[w - weights[i]]; // take the current item
                }
                curr[w] = max(take, notTake); // return the maximum value
            }
            prev = curr;
        }

        return prev[capacity]; // return the maximum value for the last item and the target capacity

    }

};


// tabulation without space optimization
class Solution {
public:

    int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {

        int n = weights.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for(int w=0; w<=capacity; w++) {
            dp[0][w] = (w / weights[0]) * values[0]; // take as many of the first item as possible
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=capacity; w++) {
                int notTake = dp[i - 1][w]; // not take the current item
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + dp[i][w - weights[i]]; // take the current item
                }
                dp[i][w] = max(take, notTake); // return the maximum value
            }
        }

        return dp[n - 1][capacity]; // return the maximum value for the last item and the target capacity

    }
};



// memoization solution
class Solution {
public:

    int solve(int idx, int w, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {

        if(idx == 0) {
            return (w / weights[0]) * values[0]; // take as many of the first item as possible
        }

        if(dp[idx][w] != -1) return dp[idx][w];

        int notTake = solve(idx - 1, w, weights, values, dp); // not take the current item
        int take = INT_MIN;

        if(weights[idx] <= w) {
            take = values[idx] + solve(idx, w - weights[idx], weights, values, dp); // take the current item
        }

        return dp[idx][w] = max(take, notTake); // return the maximum value

    }

    int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {

        int n = weights.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, capacity, weights, values, dp); // start from the last item

    }
};



// recursive solution
class Solution {
public:

    int solve(int idx, int w, vector<int>& weights, vector<int>& values) {

        if(idx == 0) {
            return (w / weights[0]) * values[0]; // take as many of the first item as possible
        }

        int notTake = solve(idx - 1, w, weights, values); // not take the current item
        int take = INT_MIN;

        if(weights[idx] <= w) {
            take = values[idx] + solve(idx, w - weights[idx], weights, values); // take the current item
        }

        return max(take, notTake); // return the maximum value

    }

    int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {

        int n = weights.size();
        return solve(n - 1, capacity, weights, values); // start from the last item

    }
};