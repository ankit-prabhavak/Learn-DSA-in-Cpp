#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// LeetCode 560. Subarray Sum Equals K

// Brute Force Approach
// class Solution {
//     public:
//         int subarraySum(vector<int>& nums, int k) {
//             int count = 0;
//             int n = nums.size();

//             for(int i = 0; i < n; i++) {
//                 int sum = 0;
//                 for(int j = i; j < n; j++) {
//                     sum += nums[j];
//                     if(sum == k) {
//                         count++;
//                     }
//                 }
//             }
//             return count;
//         }
//     };


// Optimized Approach using HashMap
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {

        
            int n = nums.size();
            vector<int> prefixSum(n, 0);
            int count = 0;
           
            unordered_map<int, int> Map;
            
            prefixSum[0] = nums[0];
            for(int i = 1; i < n; i++) {
                
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }

            for(int i = 0; i < n; i++) {
            
                if(prefixSum[i] == k) {
                    count++;
                }
                
                int value =  prefixSum[i] - k;
                if(Map.find(value) != Map.end()) {
                    count += Map[value];
                }

                if(Map.find(prefixSum[i]) == Map.end()) {
                    Map[prefixSum[i]] = 1;
                } else {
                    Map[prefixSum[i]]++;
                }

            }

            return count;
            
        }
    };



int main() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = s.subarraySum(nums, k);
    
    cout << "Number of subarrays with sum " << k << ": " << result << endl;
    
    return 0;
}
