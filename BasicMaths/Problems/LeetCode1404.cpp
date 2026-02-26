#include <iostream>
#include <string>
using namespace std;



// Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One 

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.size();

        // Traverse from right to left, but stop before the first bit
        for (int i = n - 1; i > 0; --i) {
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0) {
                // Even -> divide by 2
                steps += 1;
            } else {
                // Odd -> add 1 (1 step), then divide by 2 (1 step)
                steps += 2;
                carry = 1; // adding 1 causes a carry
            }
        }

        // After processing all bits except the MSB,
        // if there's a carry, we need one extra step
        return steps + carry;
    }
};