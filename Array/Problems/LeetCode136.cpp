#include <iostream>
#include <vector>
using namespace std;


// LeetCode 136: Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution {
public:
    int singleNumber(vector<int> & nums) {
        int n = 0;
        for(int i : nums){
            n^= i;
        }
      
      return n;
        
    }
};

// Logic Explanation:
// We can use the XOR bitwise operation to solve this problem efficiently.
// The XOR operation has the following properties:
// 1. a ^ a = 0 (any number XORed with itself is 0)
// 2. a ^ 0 = a (any number XORed with 0 is the number itself)
// 3. XOR is commutative and associative, meaning the order of operations does not matter.
// By XORing all the numbers in the array together, the numbers that appear twice will cancel each other out
// (resulting in 0), and we will be left with the single number that appears only once.
// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(1) since we are using only a constant amount of extra space.
