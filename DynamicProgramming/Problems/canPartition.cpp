#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem: Partition Equal Subset Sum
// Leetcode: 416


// Used the subset sum problem to solve this problem. The idea is to find if there exists a subset of the given array 
// with sum equal to total_sum/2. 
// If such a subset exists, then the other subset will also have the same sum, thus partitioning the array into two equal subsets.

class Solution {
public:

  // Tabulation solution with space optimization
  bool solve_with_tabulation_space_optimization(int n, int sum, vector<int>& arr) {
        vector<bool> prev(sum+1, false), curr(sum+1, false);

        prev[0] = curr[0] = true;

        if(arr[0] <= sum) {
            prev[arr[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if(arr[i] <= j) {
                    take = prev[j-arr[i]];
                }
                curr[j] = take | notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;

        for(auto ele : nums ) {
            total_sum += ele;
        }

        if(total_sum % 2 != 0) return false;

        return solve_with_tabulation_space_optimization(n, total_sum / 2, nums);
        
    }
};