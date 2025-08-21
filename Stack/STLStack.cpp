#include <iostream>
#include <stack>

using namespace std;


int main() {
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    cout << "The stack is: ";
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    cout << endl;

    // Attempt to pop from an empty stack
    if (s.empty()) {
        cout << "Stack Underflow" << endl;
    }

    // Attempt to get the top element from an empty stack
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }

    // Check if the stack is empty
    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}

