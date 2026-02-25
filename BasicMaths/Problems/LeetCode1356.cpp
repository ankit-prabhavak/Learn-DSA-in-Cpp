#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            if (ca == cb) 
                return a < b;      // tie-break by value
            return ca < cb;        // sort by popcount
        });
        return arr;
    }
};