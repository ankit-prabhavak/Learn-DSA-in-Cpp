#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Interval {
    public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


 class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
    
            sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a.start < b.start; });
    
            priority_queue<int, vector<int>, greater<int>>minHeap;
    
            for(auto i: intervals){
                if(!minHeap.empty() && minHeap.top() <= i.start)
                    minHeap.pop();
                
                minHeap.push(i.end);
                
            }
            
            return minHeap.size();
        }
    };
    
int main(){
    Solution s;
    vector<Interval> intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    cout << "Minimum number of meeting rooms required: " << s.minMeetingRooms(intervals) << endl;
    
    // Output: 2
    // Explanation: The first two intervals (0, 30) and (5, 10) overlap, so we need two meeting rooms.
    // The third interval (15, 20) does not overlap with the first two, so we can use the same room for it.
    return 0;
}