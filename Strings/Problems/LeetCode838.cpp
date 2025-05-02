#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:
        string pushDominoes(string dominoes) {
            string result;
            char last = 'L';  // Pretend there's an implicit 'L' at the start
            int i = 0, n = dominoes.size();
    
            while (i < n) {
                if (dominoes[i] == '.') {
                    int start = i;
                    while (i < n && dominoes[i] == '.') i++;
                    int count = i - start;
    
                    char next = (i < n) ? dominoes[i] : 'R';  // Look ahead
    
                    if (last == 'R' && next == 'L') {
                        int half = count / 2;
                        result += string(half, 'R');
                        if (count % 2 == 1) result += ".";
                        result += string(half, 'L');
                    } else if (last == 'R') {
                        result += string(count, 'R');
                    } else if (next == 'L') {
                        result += string(count, 'L');
                    } else {
                        result += string(count, '.');
                    }
                } else {
                    result += dominoes[i];
                    last = dominoes[i];
                    i++;
                }
            }
    
            return result;
        }
    };

int main() {
    Solution solution;
    string dominoes = ".L.R...LR..L..";
    string result = solution.pushDominoes(dominoes);
    cout << result << endl;  // Output: "LL.RR.LLRRLL.."
    return 0;
}

// This code defines a class Solution with a method pushDominoes that simulates the falling of dominoes based on the given rules. The main function tests this method with an example input.