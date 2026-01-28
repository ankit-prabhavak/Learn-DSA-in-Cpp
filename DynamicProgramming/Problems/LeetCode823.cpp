#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// LeetCode 823. Binary Trees With Factors
// Approach: Dynamic Programming + Hashing
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        // sort the array for consistent factorization
        sort(arr.begin(), arr.end());
        // dp[i] will store the number of binary trees with root as arr[i]
        unordered_map<int, long long> dp;
        // Using a set for O(1) lookups
        unordered_set<int> s(arr.begin(), arr.end());
        

        for (int i = 0; i < arr.size(); ++i) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && s.count(arr[i] / arr[j])) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
                }
            }
        }

        long long result = 0;
        for (const auto& pair : dp) {
            result = (result + pair.second) % MOD;
        }

        return result;
    }
};


// Example usage
int main() {
    Solution solution;
    vector<int> arr = {2, 4, 5, 10};
    int result = solution.numFactoredBinaryTrees(arr);
    cout << "Number of binary trees: " << result << endl; // Output: 7
    return 0;
}

/*
Real-life analogy (very important)

Suppose:

You have 3 shirts

You have 4 pants

How many outfits can you make?

👉 For each shirt, you can wear any pant
*/