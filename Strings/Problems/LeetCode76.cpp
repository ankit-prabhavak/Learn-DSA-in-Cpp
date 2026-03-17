#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// Leetcode 76: Minimum Window Substring (Sliding Window + Frequency Map)

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // Step 1: store frequency of t
        for (char c : t) {
            mp[c]++;
        }

        int left = 0, right = 0;
        int count = t.size(); // number of chars we still need
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            // Step 2: include current char
            if (mp[s[right]] > 0) {
                count--;
            }
            mp[s[right]]--;
            right++;

            // Step 3: valid window found
            while (count == 0) {
                // update answer
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Step 4: shrink window
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};