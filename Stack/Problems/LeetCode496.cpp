#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;



// LeetCode 496: Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;  
        unordered_map<int, int> nextMap;  // stores next greater for each element

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Maintain decreasing stack
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack not empty, top is the next greater
            nextMap[nums2[i]] = st.empty() ? -1 : st.top();

            // Push current element to stack
            st.push(nums2[i]);
        }

        // Build result for nums1
        for (int num : nums1) {
            ans.push_back(nextMap[num]);
        }

        return ans;
    }
};