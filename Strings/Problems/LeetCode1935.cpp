#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        bool hasBroken = false;

        for (char c : text) {
            if (c == ' ') {
                if (!hasBroken) ans++;
                hasBroken = false;  // reset for next word
            } else if (broken.count(c)) {
                hasBroken = true;
            }
        }

        // Last word check
        if (!hasBroken) ans++;

        return ans;
    }
};

int main() {
    Solution sol;
    string text = "Hello world";
    string broken = "ad";

    int result = sol.canBeTypedWords(text, broken);
    cout << "Total numbers of word: " << result << endl;

    return 0;
}