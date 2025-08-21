#include <iostream>
#include <list>

using namespace std;


class Stack {
    list<int> l;

public:
    void push(int data) {
        l.push_front(data);
        cout << data << " pushed to stack" << endl;
    }

    int pop() {
        if (l.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = l.front();
        l.pop_front();
        cout << data << " popped from stack" << endl;
        return data;
    }

    int top() {
        if (l.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return l.front();
    }

    bool isEmpty() {
        return l.empty();
    }
};

int main() {

    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "The stack is: ";
    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    s.pop(); // Attempt to pop from an empty stack
    s.top(); // Attempt to get the top element from an empty stack
    s.isEmpty(); // Check if the stack is empty

    return 0;
}