#include <iostream>
#include <stack>

using namespace std;

// Geeks for Geeks: Sort a Stack


// Approach: Iterative 
class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        
        stack<int> tempStack;

        while(!st.empty()) {
            int temp = st.top();
            st.pop();

            while(!tempStack.empty() && tempStack.top() > temp) {
                st.push(tempStack.top());
                tempStack.pop();
            }

            tempStack.push(temp);
        }
        
        while(!tempStack.empty()) {
            st.push(tempStack.top());
            tempStack.pop();
        }

    }
};

// Approach: Recursive
class Solution {
  public:
    void insert(stack<int> &st, int temp) {
        if(st.empty() || st.top() <= temp) {
            st.push(temp);
            return;
        }

        int top = st.top();
        st.pop();

        insert(st, temp);

        st.push(top);
    }

    void sortStack(stack<int> &st) {
        if(st.empty()) {
            return;
        }

        int temp = st.top();
        st.pop();

        sortStack(st);

        insert(st, temp);
    }
};
