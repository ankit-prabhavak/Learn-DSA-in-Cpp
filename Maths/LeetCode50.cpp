#include <iostream>
using namespace std;

// LeetCode Problem 50: Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// Approach: We can use the method of exponentiation by squaring to efficiently compute x^n in O(log n) time. 
// This method works by recursively breaking down the problem into smaller subproblems, reducing the number of multiplications needed.
// Time Complexity: O(log n) due to the recursive halving of the exponent.

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==0) return 0.0;
        if(x==1) return 1.0;
        if(x==-1 && n%2==0) return 1.0;
        if(x==-1 && n%2!=0) return -1.0;


        long bin = n;
        if(n<0){
            x = 1/x;
            bin = -bin;
        }
        double ans = 1;
        while(bin > 0){
            if(bin % 2 == 1){
                ans *= x;

            }
            x = x*x;
            bin/= 2;
        }
        return ans;
    }
};


int main() { 
    Solution s;
    cout << s.myPow(2.00000, 10) << endl; // Output

    return 0;
}