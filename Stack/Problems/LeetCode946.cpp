#include <vector>
#include <stack>

using namespace std;

// LeetCode 946: Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // Stack to simulate push/pop
        int j = 0;     // Pointer for popped array
        
        for (auto val : pushed) {
            st.push(val); 
            // Pop while top matches popped[j]
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty(); // Valid if stack is empty
    }
};