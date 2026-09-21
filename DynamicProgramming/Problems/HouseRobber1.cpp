#include <iostream>
#include <vector>
using namespace std;


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
    
    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            int include = nums[i] + (i > 1 ? dp[i - 2] : 0);
            int exclude = dp[i - 1];
            
            dp[i] = max(include, exclude);
        }
        
        return dp[n-1];
    }
    
    int robHelper(int index, vector<int>& nums, vector<int>& dp) {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int include = nums[index] + robHelper(index - 2, nums, dp);
        int exclude = robHelper(index - 1, nums, dp);
        
        dp[index] = max(include, exclude);
        return dp[index];
    }
    
    int robRecursive(vector<int>& nums, int index) {
        if(index == 0) return nums[index];

        if(index < 0) return 0;
        
        int include = nums[index] + robRecursive(nums, index - 2);
        int exclude = robRecursive(nums, index - 1);
        
        return max(include, exclude);
        
    }

    int rob(vector<int>& nums) {
          
        //   return robRecursive(nums, nums.size()-1); TLE

        // int n = nums.size();

        // vector<int> dp(n, -1);

        // return robHelper(n-1, nums, dp); Not space optimized


        // return robTabulation(nums); little space optimized O(N)

        return robSpaceOptimized(nums); // Best Time O(N) and Space O(1)

    }
};



