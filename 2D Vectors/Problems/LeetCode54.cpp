#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();

            int top = 0, bottom = m - 1;
            int left = 0, right = n - 1;
            vector<int> result;
            while(top <= bottom && left <= right) {
                // Traverse the top row
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                
                // Traverse the right column
                for (int i = top+1; i <= bottom; i++) {
                   
                    result.push_back(matrix[i][right]);
                }
            
                // Traverse the bottom row

                for(int i = right-1; i >= left; i--) {
                    if(top == bottom) break; // Avoid double counting the last row
                    result.push_back(matrix[bottom][i]);
                }
                

                // Traverse the left column
                for(int i = bottom-1; i >= top+1; i--) {
                    if(left == right) break; // Avoid double counting the last column
                    result.push_back(matrix[i][left]);
                }
                left++;
                right--;
                top++;
                bottom--;
             }

            return result;
        }
    };





int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = sol.spiralOrder(matrix);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}