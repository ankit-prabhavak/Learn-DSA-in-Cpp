#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*

Problem:

There is a theif who wants to steal the maximum value of gold from a shop. 
The shop has n bags, each bag contains a certain amount of gold. The thief can only steal from a bag if he can carry the entire bag. 
The thief has a maximum weight capacity of W. Each bag has a weight and a value associated with it. 
The thief wants to maximize the total value of gold he steals without exceeding his weight capacity.

Example:
Input:
n = 3, W = 4
weights = {1, 2, 3}
values = {1, 2, 3}

Output:
The maximum value of gold the thief can steal is 4.

Example Explanation:
The thief can steal the bags with weights 1 and 3, which have a total weight of 4 and a total value of 4.


Example: 
Input:
n = 3, W = 8
weights = {3, 4, 5}
values = {30, 40, 60}

Output:
The maximum value of gold the thief can steal is 90.

*/

// tabulation solution with space optimization using single array
class Solution {
public:
     
    int knapsack(vector<int> &weights, vector<int> &values, int n, int maxWeight) {
        vector<int> dp(maxWeight+1, 0);

        for(int w=weights[0]; w<=maxWeight; w++) {
            dp[w] = values[0];
        }

        for(int i=1; i<n; i++) {
            for(int w=maxWeight; w>=0; w--) {
                int notTake = dp[w];
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + dp[w-weights[i]];
                }
                dp[w] = max(take, notTake);
            }
        }

        return dp[maxWeight];
    }
};


// tabulation solution with space optimization using previous and current arrays
class Solution {
public:
     
    int knapsack(vector<int> &weights, vector<int> &values, int n, int maxWeight) {
        vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

        for(int w=weights[0]; w<=maxWeight; w++) {
            prev[w] = values[0];
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=maxWeight; w++) {
                int notTake = prev[w];
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + prev[w-weights[i]];
                }
                curr[w] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[maxWeight];
    }
};



// tabulation solution
class Solution {
public:

    int knapsack(vector<int> &weights, vector<int> &values, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

        for(int w=weights[0]; w<=maxWeight; w++) {
            dp[0][w] = values[0];
        }

        for(int i=1; i<n; i++) {
            for(int w=0; w<=maxWeight; w++) {
                int notTake = dp[i-1][w];
                int take = INT_MIN;
                if(weights[i] <= w) {
                    take = values[i] + dp[i-1][w-weights[i]];
                }
                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n-1][maxWeight];
    }
};


// memoization solution
class Solution {
public:

    int knapsack(vector<int> &weights, vector<int> &values, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
        return solve(n-1, maxWeight, weights, values, dp);
    }

    int solve(int index, int maxWeight, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp) {
        if(index == 0) {
            if(weights[0] <= maxWeight) {
                return values[0];
            } else {
                return 0;
            }
        }

        if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

        int notTake = solve(index-1, maxWeight, weights, values, dp);
        int take = INT_MIN;

        if(weights[index] <= maxWeight) {
            take = values[index] + solve(index-1, maxWeight - weights[index], weights, values, dp);
        }

        return dp[index][maxWeight] = max(take, notTake);
    }
};



// recursive solution
class Solution {
public:

    int knapsack(vector<int> &weights, vector<int> &values, int n, int maxWeight) {
        return solve(n-1, maxWeight, weights, values);
    }    

    int solve(int index, int maxWeight, vector<int> &weights, vector<int> &values) {
        if(index == 0) {
            if(weights[0] <= maxWeight) {
                return values[0];
            } else {
                return 0;
            }
        }

        int notTake = solve(index-1, maxWeight, weights, values);
        int take = INT_MIN;

        if(weights[index] <= maxWeight) {
            take = values[index] + solve(index-1, maxWeight - weights[index], weights, values);
        }

        return max(take, notTake);
    }
};


