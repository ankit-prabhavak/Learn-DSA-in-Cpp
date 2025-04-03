#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
    public:
        int reverse(int x) {
           int reversed = 0;
           
           while (x != 0) {
            if(reversed > INT_MAX/10 || reversed < INT_MIN/10) return 0;
    
            reversed = reversed * 10 + x % 10;
            x /= 10;
           }
         return reversed;
        }
        bool isPalindrome(int x) {
            if(x < 0) return false;
    
            int rev = reverse(x);
            return rev == x;
          
        }
    };
    

int main() {
    Solution s;
    int x = 12345; // Example number
    cout << "Original number: " << x << endl;
    cout << "Reversed number: " << s.reverse(x) << endl;
    
    cout << "Is Palindrome: " << s.isPalindrome(x) << endl;
    
    return 0;
}
// Output: Original number: 12345    