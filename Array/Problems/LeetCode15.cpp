#include <vector>
#include <algorithm>
using namespace std;


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