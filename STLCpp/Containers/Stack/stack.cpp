#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s; // stack of integers
    stack<int> s1; // default constructor
    stack<int> s2(s1); // copy constructor independent of s1




    s.push(1); // push 1 onto the stack
    s.push(2); // push 2 onto the stack
    s.push(3); // push 3 onto the stack
    s.push(4); // push 4 onto the stack
    s.emplace(5); // emplace 5 onto the stack (in-place object creation)
    s.emplace(6); // emplace 6 onto the stack (in-place object creation)


    s1.push(7); // push 7 onto the stack s1
    s1.push(8); // push 8 onto the stack s1
    s1.push(9); // push 9 onto the stack s1
    s1.push(10); // push 10 onto the stack s1
    s2.swap(s1); // swap the contents of s and s1 both exchange their contents

    cout << "s1: " << s1.top() << endl; // print the top element of s1 (10)
    cout << "s1 size: " << s1.size() << endl; // print the size of s1 (4)
    cout << "s2: " << s2.top() << endl; // print the top element of s2 (7)



    s.pop(); // pop the top element (6) from the stack
    cout << "Top element: " << s.top() << endl; // print the top element (5)
    cout << "Size of stack: " << s.size() << endl; // print the size of the stack (5)
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // check if the stack is empty

    while(!s.empty()) { // while the stack is not empty
        cout << s.top() << " "; // print the top element
        s.pop(); // pop the top element
    }
    cout << endl; // print a newline

    cout << "Size of stack after popping all elements: " << s.size() << endl; // print the size of the stack (0)

    

   

    return 0;
}