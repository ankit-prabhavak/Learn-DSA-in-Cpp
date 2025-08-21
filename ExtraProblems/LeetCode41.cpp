#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Brute Force Approach
class Solution {
public:
    int helper(const vector<int>& hu, int low, int high) {
        if (low > high) return 0;
        auto max_iterator = std::max_element(hu.begin() + low, hu.begin() + high + 1);
        return *max_iterator;
    }

    int trap(vector<int>& height) {
        int rain = 0;
        int n = height.size();
        for (int i = 1; i < n - 1; i++) {
            int left_max = helper(height, 0, i - 1);
            int right_max = helper(height, i + 1, n - 1);
            int water = min(left_max, right_max) - height[i];
            if (water > 0)
                rain += water;
        }
        return rain;
    }
};


// Optimized Approach using Two Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int left_max = height[left], right_max = height[right];
        int rain = 0;

        while (left < right) {
            if (left_max < right_max) {
                left++;
                left_max = max(left_max, height[left]);
                rain += left_max - height[left];
            } else {
                right--;
                right_max = max(right_max, height[right]);
                rain += right_max - height[right];
            }
        }
        return rain;
    }
};