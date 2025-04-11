#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void allSubarray(vector<int>& arr, vector<int>& subarr, int i, vector<vector<int>>& allSubsets) {
        if (i == arr.size()) {
            allSubsets.push_back(subarr);
            return;
        }

        // Include the current element in the subarray
        subarr.push_back(arr[i]);
        allSubarray(arr, subarr, i + 1, allSubsets);

        // Skip duplicates
        int idx = i + 1;
        while (idx < arr.size() && arr[idx] == arr[idx - 1]) idx++;

        // Exclude the current element from the subarray
        subarr.pop_back();
        allSubarray(arr, subarr, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        allSubarray(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = s.subsetsWithDup(nums);

    cout << "Unique subsets:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}