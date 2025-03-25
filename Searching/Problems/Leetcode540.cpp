#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {

            if(nums.size() == 1) return nums[0];

            int start = 0, end = nums.size() - 1;

            while(start <= end){
                int mid = start + (end - start) / 2;


                if(mid == 0 && nums[0] != nums[1]) return nums[mid];
                if(mid == end && nums[end] != nums[end-1]) return nums[mid];

                if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) return nums[mid];

                if(mid % 2 == 0){

                    if(nums[mid-1] == nums[mid]){
                        end = mid - 1;
                    }else{
                        start = mid + 1;
                    }

                }else{

                    if(nums[mid-1] == nums[mid]){
                        start = mid + 1;
                }else{
                    end = mid-1;
                }
            }
            
        }
        return -1;
    }
    };






int main(){
    Solution solution;
    vector<int> nums = {1,1,2,3,3,4,4};

    cout << solution.singleNonDuplicate(nums) << endl;

    return 0;
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/

/*
Leetcode 540:
You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/