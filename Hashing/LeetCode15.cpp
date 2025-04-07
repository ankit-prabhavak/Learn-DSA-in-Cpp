#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


// Brute Force Approach
// class Solution {
//     public:
//         vector<vector<int>> threeSum(vector<int>& nums) {
//             vector<vector<int>> result;
//             int n = nums.size();

//             set<vector<int>> uniqueTriplets;

//             for(int i = 0; i < n; i++){
//                 for(int j = i+1; j < n; j++){
//                     for(int k = j+1; k < n; k++){
                       
//                             if(nums[i] + nums[j] + nums[k] == 0){
//                                 vector<int> triplet = {nums[i], nums[j], nums[k]};
//                                 sort(triplet.begin(), triplet.end());

//                                 // Check if the triplet is unique
//                                 if(uniqueTriplets.find(triplet) == uniqueTriplets.end()){
//                                     uniqueTriplets.insert(triplet);
//                                     // Add the triplet to the result
//                                     result.push_back(triplet);
//                                 }
                                
//                             }
                        
//                     }
//                 }
//             }


//             return result;

            
//         }
//     };


// Optimized Approach Using Hash Set
// class Solution {
//     public:
//         vector<vector<int>> threeSum(vector<int>& nums) {
            
//             int n = nums.size();
//             set<vector<int>> uniqueTriplets;

//             for(int i = 0; i < n; i++){
//                 int target = -nums[i];
//                 set<int> seen;

//                 for(int j = i+1; j <n; j++){
//                     int complement = target - nums[j];

//                     // Check if the complement is in the seen set
//                     if(seen.find(complement) != seen.end()){
//                         vector<int> triplet = {nums[i], nums[j], complement};
//                         sort(triplet.begin(), triplet.end());
//                         uniqueTriplets.insert(triplet);
                    
//                     }

//                     // Add the current number to the seen set
//                     seen.insert(nums[j]);

//                 }
//             }
//             vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
//             return result;
            
//         }
//     };

// // Two Pointer Approach Most Optimized
// class Solution {
//     public:
//         vector<vector<int>> threeSum(vector<int>& nums) {
//             int n = nums.size();
//             vector<vector<int>> result;

//             // Sort the input array
//             sort(nums.begin(), nums.end());

//             for(int i = 0; i < n ; i++){
//                 int j = i + 1;
//                 int k = n - 1;

//                 // Skip duplicates for the first element
//                 if(i > 0 && nums[i] == nums[i - 1]) continue;

//                 while(j < k){
//                     int sum = nums[i] + nums[j] + nums[k];

//                     if(sum == 0){
//                         result.push_back({nums[i], nums[j], nums[k]});
//                         // Move both pointers to find the next unique triplet
//                         while(j < k && nums[j] == nums[j + 1]) j++;
//                         while(j < k && nums[k] == nums[k - 1]) k--;
//                         j++;
//                         k--;
//                     }
//                     else if(sum < 0){
//                         j++;
//                     }
//                     else{
//                         k--;
//                     }
//                 }
//             }
            
//             return result;
//         }
//     };

// Two Pointer Approach Most Optimized
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> result;

            // Sort the input array
            sort(nums.begin(), nums.end());

            for(int i = 0; i < n ; i++){
                int j = i + 1;
                int k = n - 1;

                // Skip duplicates for the first element
                if(i > 0 && nums[i] == nums[i - 1]) continue;

                while(j < k){
                    int sum = nums[i] + nums[j] + nums[k];

                    if(sum < 0){
                        j++;
                    }
                    else if(sum > 0){
                        k--;
                    }
                    else{
                        result.push_back({nums[i], nums[j], nums[k]});     
                        j++;
                        k--;

                        while(j < k && nums[j] == nums[j - 1]) j++;
                    }
                }
            }
            
            return result;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    
    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}