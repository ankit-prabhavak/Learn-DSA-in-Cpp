#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
    void allSubarray(vector<int>&arr, vector<int>&subarr, int i, vector<vector<int>>&allSubsets ){
        if(i == arr.size()){
            allSubsets.push_back(subarr);
            return;
        }
    
        //Include the current element in the subarray
        subarr.push_back(arr[i]);
        allSubarray(arr, subarr, i + 1, allSubsets);
    
        //Exclude the current element from the subarray
        subarr.pop_back();
        allSubarray(arr, subarr, i + 1, allSubsets);
       
    }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>allSubsets;
    
            vector<int>ans;
    
            allSubarray(nums, ans, 0, allSubsets);
    
            return allSubsets;
            
        }
    };


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}

