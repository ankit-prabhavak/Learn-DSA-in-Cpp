#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int piv = -1;
    
            // Step 1: Find the first element from the right that is smaller than the next one
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    piv = i;
                    break;
                }
            }
    
            if (piv == -1) {
                // If no such element is found, the array is in descending order. Reverse the entire array
                reverse(nums.begin(), nums.end());
            } else {
                // Step 2: Find the smallest element in the suffix greater than nums[piv]
                for (int i = n - 1; i > piv; i--) {
                    if (nums[i] > nums[piv]) {
                        swap(nums[i], nums[piv]);
                        break;
                    }
                }
    
                // Step 3: Reverse the part of the array after the pivot
                reverse(nums.begin() + piv + 1, nums.end());
            }
        }
    };


int main(){
    Solution solution;
    vector<int> nums = {2, 3, 7, 6, 5, 1};
    solution.nextPermutation(nums);


    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }


    return 0;
}