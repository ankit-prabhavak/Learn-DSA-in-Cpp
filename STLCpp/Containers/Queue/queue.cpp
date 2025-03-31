#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<int> q; // queue of integers
    queue<int> q1; // default constructor
    queue<int> q2(q1); // copy constructor independent of q1
    
    q.push(1); // push 1 onto the queue
    q.push(2); // push 2 onto the queue
    q.push(3); // push 3 onto the queue
    q.push(4); // push 4 onto the queue
    q.emplace(5); // emplace 5 onto the queue (in-place object creation)
    q.emplace(6); // emplace 6 onto the queue (in-place object creation)

    q1.push(7); // push 7 onto the queue q1
    q1.push(8); // push 8 onto the queue q1
    q1.push(9); // push 9 onto the queue q1
    q1.push(10); // push 10 onto the queue q1

    q2.swap(q1); // swap the contents of q and q1 both exchange their contents

    cout << "q1: " << q1.front() << endl; // print the front element of q1 (10)
    cout << "q1 size: " << q1.size() << endl; // print the size of q1 (4)
    cout << "q2: " << q2.front() << endl; // print the front element of q2 (7)


    while(!q.empty()) { // while the queue is not empty
        cout << q.front() << " "; // print the front element
        q.pop(); // pop the front element
    }
    cout << endl; // print a newline

    cout << "Size of queue after popping all elements: " << q.size() << endl; // print the size of the queue (0)
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // check if the queue is empty
    cout << "Size of queue: " << q.size() << endl; // print the size of the queue (0)

    
    return 0;
}