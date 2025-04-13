#include <iostream>


using namespace std;


// LeetCode 1922. Count Good Numbers
class Solution {
    public:
        long long helper(long long base, long long expo, long long mod) {
            long long ans = 1;
            while (expo > 0) {
                if (expo % 2 == 0) {
                    base = (base * base) % mod;
                    expo = expo / 2;
                } else {
                    ans = (ans * base) % mod;
                    expo -= 1;
                }
            }
            return ans;
        }
    
        int countGoodNumbers(long long n) {
            long long even = (n + 1) / 2;
            long long odd = n / 2;
            long long mod = 1e9 + 7;
            return (int)((helper(5, even, mod) * helper(4, odd, mod)) % mod);
        }
    };

int main() {
    Solution sol;
    long long n = 50; // Example input
    cout << "Count of good numbers: " << sol.countGoodNumbers(n) << endl;
    return 0;
}
// This code defines a class Solution with a method countGoodNumbers that calculates the number of good numbers of length n.