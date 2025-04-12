#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:

    void getPerms(vector<int>&nums, int idx, vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i = idx; i <nums.size(); i++){
            swap(nums[idx], nums[i]);
            getPerms(nums, idx+1, ans);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getPerms(nums, 0,ans);
        return ans;
    
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    cout << "All permutations:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}