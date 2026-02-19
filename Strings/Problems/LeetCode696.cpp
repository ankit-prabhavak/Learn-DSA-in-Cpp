#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;   // length of previous group
        int curr = 1;   // length of current group
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;  // same group, increase current count
            } else {
                ans += min(prev, curr); // count valid substrings
                prev = curr;            // move current to previous
                curr = 1;               // reset current group count
            }
        }

        // add for the last group pair
        ans += min(prev, curr);

        return ans;
    }
};