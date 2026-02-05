#include <vector>
#include <iostream>
using namespace std;

// LeetCode Problem 3379: Construct the Transformed Array

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0) {
                result[i] = 0;
                continue;  // important!
            }

            int index = (i + nums[i]) % n;
            if(index < 0) index += n;  // fix negative wrap

            result[i] = nums[index];
        }

        return result;
    }
};

int main() { 
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> transformed = s.constructTransformedArray(nums);
    for (int num : transformed) {
        cout << num << " ";
    }
    cout << endl; // Output: 24 12 8 6

    return 0;
}