#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1, 0); 
        
        // Compute prefix sums
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        deque<int> dq; 
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Check if the current subarray satisfies the condition
            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain the deque in increasing order of prefix sums
            while (!dq.empty() && preSum[i] <= preSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, -1, 2};
    int k = 3;

    cout << "Shortest subarray length: " << s.shortestSubarray(nums, k) << endl;

    return 0;
}


// Brute Force Approach: 

// class Solution {
//     public:
//         int shortestSubarray(vector<int>& nums, int k) {
            
//             int answer = INT_MAX;
    
//             for(int i = 0; i < nums.size(); i++){
//                 int sum = 0;
    
//                 for(int j = i; j < nums.size(); j++){
//                     sum += nums[j];
    
//                     if(sum >= k){
//                         answer = min(answer, j- i +1);
//                         break;
//                     }
//                 }
//             }
            
//             if(answer == INT_MAX)
//                 return -1;
//             else
//                return answer;
            
//         }
//     };



