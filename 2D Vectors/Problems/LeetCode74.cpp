#include <iostream>
#include <vector>

using namespace std;



class Solution {
    public:

    bool binarySearch(vector<vector<int>>& matrix, int row, int target){
        int n = matrix[0].size();

        
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }

       
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            int row = matrix.size();
            int col = matrix[0].size();

            int start = 0, end = row-1;

            while(start <= end){
                int mid = start + (end - start) / 2;

                if(target  >= matrix[mid][0] && target <= matrix[mid][col-1]){
                    // found row
                    return binarySearch(matrix, mid, target);

                }else if(target >= matrix[mid][col-1]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }

          return false;
            
        }
    };

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 23, 31, 55}};

    int target  = 23;
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;
    

    return 0;
}