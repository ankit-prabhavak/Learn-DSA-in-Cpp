#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility> // For std::pair
#include <algorithm> // For std::max

using namespace std;


class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> freq;
    
            for(char i : tasks){
                freq[i]++;
            }
    
            priority_queue<int>maxHeap;
    
            for(auto i : freq){
                maxHeap.push(i.second);
            }
    
            queue<pair<int, int>> lq;
    
            int t = 0;
    
            while(!maxHeap.empty() || !lq.empty()){
                t++;
    
                if( !lq.empty() && lq.front().second == t){
                    maxHeap.push(lq.front().first);
                    lq.pop();
                }
    
                if(!maxHeap.empty()){
                    int count = maxHeap.top();
                    maxHeap.pop();
                    count--;
                    if(count > 0){
                        lq.push({count, t+n+1});
                    }
                }
            } 
    
            return t;
            
        }
    };


int main() {
    Solution solution;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << solution.leastInterval(tasks, n) << endl;
    // Output: 8
    return 0;
}

// Output: 8
// Explanation: One possible solution is:   "A -> B -> idle -> A -> B -> idle -> A -> B".
// The tasks are executed in the order shown, with 'idle' representing the idle time.