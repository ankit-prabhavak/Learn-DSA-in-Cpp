#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int countTop[7] = {0}, countBottom[7] = {0}, countBoth[7] = {0};
    
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] == bottoms[i]) {
                    countBoth[tops[i]] += 1;
                } else {
                    countTop[tops[i]] += 1;
                    countBoth[tops[i]] += 1;
                    countBottom[bottoms[i]] += 1;
                    countBoth[bottoms[i]] += 1;
                }
            }
    
            for (int i = 1; i <= 6; i++) { // Check for numbers 1 to 6
                if (countBoth[i] == tops.size()) { // If a number can appear on all dominoes
                    return min(countTop[i], countBottom[i]);
                }
            }
    
            return -1; // No valid number found
        }
    };

int main() {
    Solution solution;
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};
    int result = solution.minDominoRotations(tops, bottoms);
    cout << "Minimum rotations: " << result << endl; // Output: 2

    return 0;
}