#include <vector>

// Leetcode 762: Prime Number of Set Bits in Binary Representation
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Precomputed primes up to 20 (max bits for 10^6 is 19)
        // Using a simple boolean array for O(1) lookup
        bool primes[21] = {false};
        for (int p : {2, 3, 5, 7, 11, 13, 17, 19}) {
            primes[p] = true;
        }

        int answer = 0;
        for (int i = left; i <= right; i++) {
            int count = __builtin_popcount(i);
            if (primes[count]) {
                answer++;
            }
        }

        return answer;
    }
};