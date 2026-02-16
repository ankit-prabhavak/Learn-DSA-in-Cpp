// Leetcode 190: Reverse Bits

class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;

        for (int i = 0; i < 32; i++) {
            rev = (rev << 1) | (n & 1);  // take last bit of n and add to rev
            n >>= 1;                    // shift n right to get next bit
        }

        return rev;
    }
};