#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 56: Merge Intervals
// Given a collection of intervals, merge all overlapping intervals.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        if (intervals.empty()) return result;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            // If result is empty or no overlap, add interval
            if (result.empty() || intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                // Overlap: merge intervals
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
};