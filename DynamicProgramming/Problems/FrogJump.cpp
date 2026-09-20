#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

/*
Always remember if there is something in term of index - 1 and index - 2 then 
there can always be space optimization using two variables instead of using a dp array.
*/
// more optimized in term of space
int frogJumpBest(int n, vector<int>& heights) {
    
    int prev2 = 0;
    int prev1 = 0;

    for(int i = 1; i < n; i++) {
        int left = prev1 + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


/*
Tabulation reduces the time complexity to O(n) and space complexity to O(n) as we are storing the results of subproblems in a dp array.
It saves the space used by the recursion stack in the recursive approach. 
The dp array is filled iteratively, and the final result is obtained from the last element of the dp array.
*/
// More optimized using tabulation
int frogJumpTabu(int n, vector<int>& heights) {
    if(n == 0) return 0;
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n-1];
}

/*
Improves time complexity to O(n) by storing the results of subproblems in a dp array, avoiding redundant calculations.
The dp array is initialized with -1 to indicate uncomputed states.
*/
// Optimized solution using Dynamic Programming Memoization
int frogJumpMemo(int n, vector<int>& heights, vector<int>& dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int left = frogJumpMemo(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1){
        right = frogJumpMemo(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    }

    return dp[n] = min(left, right);
}


// simple recursive solution
int frogJump(int n, vector<int>& heights) {

    if(n == 0) return 0;

    int left = frogJump(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1){
        right = frogJump(n-2, heights) + abs(heights[n] - heights[n-2]);
    }

    return min(left, right);

}

int main(){
    vector<int> heights = {10, 20, 30, 40, 50};
    cout << frogJump(5, heights) << endl;
    return 0;
}