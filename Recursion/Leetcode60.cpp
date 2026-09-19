#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        // Store 1 to n and calculate (n-1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        // Convert k to 0-based indexing
        k--;

        string ans = "";

        while (true) {

            int index = k / fact;

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            if (nums.size() == 0)
                break;

            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;
    }
};