#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // For std::abs


// This code is a solution to LeetCode problem 1046: Last Stone Weight.
// Problem statement: You are given an array of integers stones where stones[i] is the weight of the ith stone.
// We are to simulate the process of smashing stones together until at most one stone remains.
// If the stones are of equal weight, they both are destroyed.
// If they are of different weights, the heavier stone is reduced by the weight of the lighter stone.
// The last stone's weight is returned, or 0 if no stones remain.


using namespace std;


class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // Create a max-heap to store stone weights.
        // By default, std::priority_queue is a max-heap.
        std::priority_queue<int> maxHeap;

        // Add all stones to the max-heap
        for (int ele : stones) {
            maxHeap.push(ele);
        }

        // Continue smashing stones as long as there are at least two stones left
        while (maxHeap.size() > 1) {
            // Get the heaviest stone
            int s1 = maxHeap.top();
            maxHeap.pop();

            // Get the second heaviest stone
            int s2 = maxHeap.top();
            maxHeap.pop();

            // If the stones have different weights, a new stone remains
            if (s1 != s2) {
                // The new stone's weight is the absolute difference
                // (s1 will always be >= s2 due to max-heap properties)
                maxHeap.push(std::abs(s1 - s2));
            }
            // If s1 == s2, both stones are destroyed, and nothing is pushed back.
        }

        // After the loop, the heap will contain either one stone or no stones.
        // If it's empty, maxHeap.size() is 0, meaning all stones were destroyed.
        // If it has one stone, maxHeap.top() will give its weight.
        if (maxHeap.empty()) {
            return 0; // No stones left
        } else {
            return maxHeap.top(); // Return the weight of the last remaining stone
        }
    }
};