#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);  // opening bracket
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();    // matched closing bracket
            } else {
                return false;   // mismatch found
            }
        }

        return stack.empty();        
    }
};