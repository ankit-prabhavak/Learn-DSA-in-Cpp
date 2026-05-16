#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse first k elements of a queue.
// The task is to reverse the first k elements of the given queue and return the modified queue.

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here

        if (q.empty() || k <= 0 || k > q.size()) {
            return q; // Return the original queue if k is out of bounds
        }

        stack<int> s; // Stack to hold the first k elements
        // Step 1: Dequeue the first k elements and push them onto the stack
        for (int i = 0; i < k; i++) {

            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue the elements from the stack back to the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move the remaining elements (if any) to the back of the queue
        int size = q.size();
        for (int i = 0; i < size - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q; // Return the modified queue
        
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue<int> modifiedQueue = sol.reverseFirstK(q, k);

    cout << "Modified Queue: ";
    while (!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    cout << endl;

    return 0;
} 