#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++) {       // hours: 0 to 11
            for (int m = 0; m < 60; m++) {   // minutes: 0 to 59
                // count total set bits in hour and minute
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    
                    // ensure minute has 2 digits
                    if (m < 10) time += "0";
                    time += to_string(m);

                    result.push_back(time);
                }
            }
        }

        return result;
    }
};