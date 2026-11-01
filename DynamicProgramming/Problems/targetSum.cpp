/*
Problem: Target Sum
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.

Example 2:
Input: nums = [1], target = 1
Output: 1
Explanation: There is 1 way to assign symbols to make the sum of nums be target 1.

*/






#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    // tabulation with space optimization
    int solveTabulationSpaceOptimized(vector<int> &num, int tar) {
        
        int n = num.size();
        vector<int> prev(tar+1, 0), curr(tar+1, 0);

        // prev[0] = curr[0] = 1;

        // if(num[0] <= tar) {
        //     prev[num[0]] = 1;
        // }


        if(num[0] == 0) {
            prev[0] = 2; // two ways: include or exclude the zero
        } else {
            prev[0] = 1; // one way: exclude the first element
        }

        if(num[0] != 0 && num[0] <= tar) {
            prev[num[0]] = 1; // one way: include the first element
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=tar; j++) {
                int notTake = prev[j];
                int take = 0;
                if(num[i] <= j) {
                    take = prev[j-num[i]];
                }
                curr[j] = (take + notTake);
            }
            prev = curr;
        }

        return prev[tar];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum - target < 0 || (sum - target) % 2 != 0) {
            return 0;
        }

        int tar = (sum - target) / 2;

        return solveTabulationSpaceOptimized(nums, tar);
        
    }
};