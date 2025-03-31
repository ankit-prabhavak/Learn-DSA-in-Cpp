#include <iostream>
#include <queue>

using namespace std;


int main(){
    priority_queue<int> pq; // max heap by default

    pq.push(1); // push 1 onto the priority queue
    pq.push(2); // push 2 onto the priority queue
    pq.push(3); // push 3 onto the priority queue
    pq.push(4); // push 4 onto the priority queue

    pq.emplace(5); // emplace 5 onto the priority queue (in-place object creation)

    while(!pq.empty()) { // while the priority queue is not empty
        cout << pq.top() << " "; // print the top element (highest priority)
        pq.pop(); // pop the top element
    }
    cout << endl; // print a newline

    cout << "Size of priority queue after popping all elements: " << pq.size() << endl; // print the size of the priority queue (0)
    cout << "Is priority queue empty? " << (pq.empty() ? "Yes" : "No") << endl; // check if the priority queue is empty

    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    minHeap.push(1); // push 1 onto the min heap
    minHeap.push(2); // push 2 onto the min heap
    minHeap.push(3); // push 3 onto the min heap
    minHeap.push(4); // push 4 onto the min heap

    minHeap.emplace(5); // emplace 5 onto the min heap (in-place object creation)
    minHeap.emplace(6); // emplace 6 onto the min heap (in-place object creation)

    while(!minHeap.empty()) { // while the min heap is not empty
        cout << minHeap.top() << " "; // print the top element (lowest priority)
        minHeap.pop(); // pop the top element
    }
    cout << endl; // print a newline

    cout << "Size of min heap after popping all elements: " << minHeap.size() << endl; // print the size of the min heap (0)
    cout << "Is min heap empty? " << (minHeap.empty() ? "Yes" : "No") << endl; // check if the min heap is empty

    //greater<int> is a functor that is used to compare the elements in the priority queue. It is used to create a min heap.
    // By default, the priority queue is a max heap, which means that the largest element is at the top.

    

    return 0;
}