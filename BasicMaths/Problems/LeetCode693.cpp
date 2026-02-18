// Leetcode 693: Has Alertnating Bits 

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

/*
Smart Trick

If a number has alternating bits, then:

Let x = n ^ (n >> 1)

For alternating bits, x becomes all 1s in binary
Example:
n = 10101
n >> 1 = 01010
x = 11111 

A number with all 1s has the property: x & (x+1)=0

*/