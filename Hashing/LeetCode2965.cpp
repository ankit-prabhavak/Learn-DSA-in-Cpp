#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans;
            unordered_set<int> seen;
            int n = grid.size();
            int actualSum = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int val = grid[i][j];
                    actualSum += val;
                    if (seen.count(val)) {
                        ans.push_back(val);
                    } else {
                        seen.insert(val);
                    }
                }
            }

            
            int expectedSum = (n*n) * (n*n + 1) / 2;
            
            int missingValue = expectedSum + ans[0] - actualSum;
            ans.push_back(missingValue);

            return ans;
        }
    };

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8}
    };
    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    cout << "Repeated Value: " << result[0] << ", Missing Value: " << result[1] << endl;
    // Output: Repeated Value: 8, Missing Value: 9


    return 0;
}