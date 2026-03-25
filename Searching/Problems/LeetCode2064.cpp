#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Leetcode 2064: Minimized Maximum of Products Distributed to Any Store

class Solution {
public:
    bool canDistribute(vector<int>& quantities, int n, int mid) {
        int stores = 0;

        for (int q : quantities) {
            stores += (q + mid - 1) / mid; // ceil(q / mid)
        }

        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, n, mid)) {
                ans = mid;
                high = mid - 1; // try smaller max
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};