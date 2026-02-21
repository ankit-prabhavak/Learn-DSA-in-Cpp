#include <vector>
using namespace std;

// Leetcode 287. Find the Duplicate Number
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = 0;
            int fast = 0;

            int n = nums.size();
            // Find the intersection point of the two runners.

            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast);

            // Find the entrance to the cycle.
            slow = 0;
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow; // or fast, both are the same at this point
            
        }
    };
