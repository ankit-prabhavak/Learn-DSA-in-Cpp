#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Leetcode 2099. Find Subsequence of Length K With the Largest Sum
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> withIndex;

        for (int i = 0; i < nums.size(); ++i) {
            withIndex.emplace_back(nums[i], i);
        }

        // Sort by value descending
        sort(withIndex.begin(), withIndex.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        // Take top k elements
        vector<pair<int, int>> selected(withIndex.begin(), withIndex.begin() + k);

        // Sort selected elements by their original index to maintain order
        sort(selected.begin(), selected.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        // Build the result
        vector<int> result;
        for (auto& p : selected) {
            result.push_back(p.first);
        }

        return result;
    }
};