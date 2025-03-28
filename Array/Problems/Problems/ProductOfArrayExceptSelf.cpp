/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.*/

#include <iostream>
#include <vector>


using namespace std;
//brute force with respect to space comlexity.
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> answer(n, 1);
//         vector<int> answer(n, 1);
//         vector<int> right(n, 1);
//         for (int i = 1; i < n; i++) {
//             answer[i] = answer[i - 1] * nums[i - 1];
//         }
//         for (int i = n - 2; i >= 0; i--) {
//             right[i] = right[i + 1] * nums[i + 1];
//         }
//         for (int i = 0; i < n; i++) {
//             answer[i] = answer[i]*right[i];
//         }
//         return answer;
//     }
// };

//optimized approach.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int  right = 1;

        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            answer[i] *= right;
        }
       
        return answer;
    }
};



int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);  
    for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
    

    return 0;
}