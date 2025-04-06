#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


// // uses unordered_set to find duplicate in an array and extra space
// class Solution {
//     public:
//         int findDuplicate(vector<int>& nums) {
//             unordered_set<int>seen;
//             int n = nums.size();
    
//             for(int i = 0; i < n; i++){
//                 int val = nums[i];
    
//                 if(seen.count(val)){
//                     return val;
                 
//                 }
//                 else{
//                     seen.insert(val);
//                 }
//             }
            
//             return -1;
//         }
//     };

// 

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = 0;
            int fast = 0;

            int n = nums.size();
            // Find the intersection point of the two runners.

            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast);

            // Find the entrance to the cycle.
            slow = 0;
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow; // or fast, both are the same at this point
            
        }
    };



int main(){
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    int result = sol.findDuplicate(nums);

    cout << "Duplicate: " << result << endl;



    return 0;
}