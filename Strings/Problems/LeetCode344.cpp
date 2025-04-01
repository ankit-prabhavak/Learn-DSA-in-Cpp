#include <iostream>
#include <string>
#include <vector>

using namespace std;


// LeetCode Problem 344: Reverse String using two pointers on char array
class Solution {
    public:

        void reverseString(vector<char>& s) {
            
            int l = 0;
            int r = s.size()-1;
    
            while(l<r){
                swap(s[l++], s[r--]);
            }
        }
    };



int main(){
    // Declare a character array
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;
    sol.reverseString(str); // Reverse the string
    cout << "Reversed string: ";
    for (char ch : str) {
        cout << ch; // This will print the reversed string "olleh"
    }
    cout << endl; // Print a new line



    return 0;
}