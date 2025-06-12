#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    // Max heap for the lower half, min heap for the upper half
    priority_queue<int> maxHeap; // left side (smaller numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side (larger numbers)

    MedianFinder() {}

    void addNum(int num) {
        // Add to maxHeap first
        maxHeap.push(num);

        // Balance: move the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Maintain size property: maxHeap can have equal or 1 more element than minHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */