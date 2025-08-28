#include <bits/stdc++.h>

using namespace std;


// LeetCode 503: Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        

        stack<int> s;
        vector<int> ans(nums.size(), 0); // answer array
        int n = nums.size();
        for(int i = 2*n-1; i >= 0; i--) {

            while (s.size() > 0 && nums[s.top()] <= nums[i%n]) { // we use i%n to simulate circular array
                s.pop();
            }

            ans[i%n] = s.empty()? -1: nums[s.top()]; // if stack is empty, it means there is no greater element to the right, so we store -1

            s.push(i%n); // push the index onto the stack
        }

        return ans;
    }
};