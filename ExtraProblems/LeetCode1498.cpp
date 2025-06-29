#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int size = nums.size();

        // Sort the array to allow two-pointer traversal
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to size n
        vector<int> powerOfTwo(size, 1);
        for (int i = 1; i < size; ++i) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        int left = 0, right = size - 1;
        int validSubsequences = 0;

        // Two-pointer approach to count valid subsequences
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                // All combinations from nums[left] to nums[right] are valid
                validSubsequences = (validSubsequences + powerOfTwo[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return validSubsequences;
    }
};
