#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end());
            string result = "";
            int n = s.length();
            for(int i = 0; i < n; i++){
                string word = "";
                while(i < n && s[i] != ' '){
                    word += s[i];
                    i++;
                }

                reverse(word.begin(), word.end());
                if(word != "") result += " " + word;
                     
            }
            return result.substr(1);
            
        }
    };

int main(){
    Solution sol;
    string s = "  hello world!  ";
    string result = sol.reverseWords(s);
    cout << "Reversed words: '" << result << "'" << endl;
    // Output: "world! hello"

    return 0;
}