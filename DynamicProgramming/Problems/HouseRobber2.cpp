#include <iostream>
#include <vector>
using namespace std;

// Leetcode 213. House Robber II

// Just there are two cases, either we take the first house or we take the last house. 
//So we can create two arrays, one without the first house and one without the last house and then we can apply the same logic as in House Robber I problem.

// There is circular arrangement of houses, so we cannot take both the first and last house. 
//Hence, we can break the problem into two cases:
// 1. Rob houses from index 0 to n-2 (excluding the last house).
// 2. Rob houses from index 1 to n-1 (excluding the first house

class Solution {
public:

        int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int prev2 = 0; // dp[i-2]
        int prev1 = nums[0]; // dp[i-1]
        
        for(int i = 1; i < n; i++) {
            int include = nums[i] + prev2;
            int exclude = prev1;
            
            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if( n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++) {
            if(i != 0) temp1.push_back(nums[i]);

            if(i != n-1) temp2.push_back(nums[i]);
        }


        return max(robSpaceOptimized(temp1), robSpaceOptimized(temp2));
        
    }
};