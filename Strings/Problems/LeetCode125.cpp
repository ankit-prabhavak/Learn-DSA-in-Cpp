#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
    public:

        bool isAlphanumeric(char c) {
            return (c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z');
        }

        bool isPalindrome(string s) {
            int l = 0;
            int r = s.size() - 1;

            while (l < r) {
                while (l < r && !isAlphanumeric(s[l])) l++;
                while (l < r && !isAlphanumeric(s[r])) r--;

                if (tolower(s[l]) != tolower(s[r])) return false;
                l++;
                r--;
            }
            return true;
            
            
        }
    };



int main(){
    Solution sol;
    string text = "Hello@&olleh";
    bool result = sol.isPalindrome(text); // Check if the string is a palindrome
    cout << "Is the string a palindrome? " << (result ? "Yes" : "No") << endl; // Output: Yes
    // This will print "Is the string a palindrome? Yes"

    return 0;
}