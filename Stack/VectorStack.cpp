#include <iostream>
#include <vector>

using namespace std;


class Stack {

    vector<int> v;

public:
    void push(int data) {
        v.push_back(data);
        cout << data << " pushed to stack" << endl;
    }

    int pop() {
        if (v.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = v.back();
        v.pop_back();
        cout << data << " popped from stack" << endl;
        return data;
    }

    int top() {
        if (v.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return v.back();
    }

    bool isEmpty() {
        return v.empty();
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

    return 0;
}