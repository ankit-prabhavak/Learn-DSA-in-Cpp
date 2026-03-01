#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        priority_queue<pair<int, int>> maxHeap;

        // Push the first 'k' elements into the max-heap
        for(int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});  // Use the correct pair syntax
        }

        // The largest element in the first window is the root of the max-heap
        result.push_back(maxHeap.top().first);

        // Now slide the window across the array
        for(int j = k; j < nums.size(); j++) {
            // Push the current element into the heap
            maxHeap.push({nums[j], j});

            // Remove elements from the heap that are out of the window's range
            while(!maxHeap.empty() && maxHeap.top().second <= j - k) {
                maxHeap.pop();
            }

            // Add the largest element in the current window
            result.push_back(maxHeap.top().first);
        }
        
        return result;
    }
};