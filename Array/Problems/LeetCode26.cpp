#include <iostream>
#include <vector>
using namespace std;

// Leetcode 26: Remove duplicate from sorted array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        int k = 1;
        int x = 0;

        for(int i = 0; i < nums.size()-1; i++) {

            if (nums[i] != nums[i+1]) {
                k++;
                nums[++x] = nums[i+1];
            }
        }

        return k;
        
    }
};