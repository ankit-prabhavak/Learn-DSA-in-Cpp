#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int total_sum = 0;

        for(auto ele : nums ) {
            total_sum += ele;
        }

        vector<bool> prev(total_sum+1, false), curr(total_sum+1, false);

        prev[0] = curr[0] = true;

        if(nums[0] <= total_sum) {
            prev[nums[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=total_sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if(nums[i] <= j) {
                    take = prev[j-nums[i]];
                }
                curr[j] = take | notTake;
            }
            prev = curr;
        }

        int ans = INT_MAX;

        for(int s1=0; s1<=total_sum/2; s1++) {
            if(prev[s1]) {
                ans = min(ans, abs(total_sum - 2*s1));
            }
        }

        return ans;
        
    }
};