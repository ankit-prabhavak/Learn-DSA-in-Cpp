#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array to apply binary search
        sort(nums.begin(), nums.end());

        long long count = 0;
        int n = nums.size();

        // Iterate over each element nums[i]
        for (int i = 0; i < n - 1; ++i) {
            // Calculate the bounds for nums[i] + nums[j]
            int leftBound = lower - nums[i];  // Lower bound for nums[j]
            int rightBound = upper - nums[i]; // Upper bound for nums[j]

            // Binary search to find the range of valid j values
            int left = lower_bound(nums.begin() + i + 1, nums.end(), leftBound) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), rightBound) - nums.begin();

            // Count the number of valid pairs for this i
            count += (right - left); // Valid pairs are between indices left and right-1
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    cout << solution.countFairPairs(nums, lower, upper) << endl; // Expected output: 6
    return 0;
}
