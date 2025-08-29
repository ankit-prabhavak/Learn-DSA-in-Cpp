#include <bits/stdc++.h>

using namespace std;

// LeetCode 42: Trapping Rain Water

// Brute Force Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for(int i = 0; i < n; i++) {
            int left = 0, right = 0; // Reset for each i

            for(int j = 0; j < i; j++) {
                left = max(left, height[j]);
            }

            for(int k = i+1; k < n; k++) {
                right = max(right, height[k]);
            }

            int minHeight = min(left, right);
            if(minHeight > height[i]) {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};

// Optimized Approach using Precomputed Arrays
class Solution {
public:
    int trap(vector<int>& height) {
         
        int n = height.size(); 
        vector<int> lMax(n, 0);
        vector<int> rMax(n, 0);
        int water = 0;

        lMax[0] = height[0];
        rMax[n-1] = height[n-1];
        

        for(int i = 1; i < n; i++) {

            lMax[i] = max( lMax[i-1], height[i]);
        }

        for(int i = n-2; i >= 0; i--) {
            rMax[i] = max( rMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            int val = min(lMax[i], rMax[i]) - height[i];

            if( val > 0) {
                water += val;
            }
        }
        
        return water;
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