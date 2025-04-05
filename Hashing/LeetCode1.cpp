#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// This is a solution to the Two Sum problem on LeetCode.
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> numMap;
            int n = nums.size();
    
            for (int i = 0; i < n; i++) {
                int complement = target - nums[i];
                if (numMap.count(complement)) {
                    return {numMap[complement], i};
                }
                numMap[nums[i]] = i;
            }
    
            return {}; 
            
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    
    return 0;
}