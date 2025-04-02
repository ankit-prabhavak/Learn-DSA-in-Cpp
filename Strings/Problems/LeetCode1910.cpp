#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::find_if
#include <cctype> // For std::tolower


using namespace std;

class Solution {
    public:
        string removeOccurrences(string& s, string& part) {
            while(s.length() > 0 && s.find(part) < s.length()){
                // Find the first occurrence of part in s
                s.erase(s.find(part), part.length());
            }
            return s; // Return the modified string
        }
    };


int main(){
    Solution sol;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = sol.removeOccurrences(s, part); // Remove occurrences of part from s
    cout << "Modified string: " << result << endl; // Output: "dab"
    // This will print "Modified string: dab"

    return 0;
}