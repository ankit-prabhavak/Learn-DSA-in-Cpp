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

// Brute Force Approach:
// The brute force approach would involve checking every possible combination of brackets to see if they are valid.
// This would be inefficient and not practical for large inputs.
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {

                if(st.empty()) return false;

                char top = st.top();

                if((ch == ')' && top == '(') ||
                   (ch == ']' && top == '[') ||
                   (ch == '}' && top == '{')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

