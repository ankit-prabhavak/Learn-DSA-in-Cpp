/*
Problem statement:
Assign C cows to N stalls such that min distance between them is largest possible.
Return largest minimum distance.

For Example:
n = 5, arr = [1, 2, 8, 4, 9] c = 3

Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
    public:

    bool isValid(vector<int>&arr, int n, int c, int minAllowed){
        int cows = 1;
        int lastStallPos = arr[0];

        for(int i : arr){
            if(i - lastStallPos >= minAllowed){
                cows++;
                lastStallPos = i;
            }

            if(cows == c)  return true;

        }
        return false;

    }

    int maxDistance(vector<int>& arr, int n, int c) {
        
        sort(arr.begin(), arr.end());

        int low = arr[0], high = arr[n-1] - arr[0];
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isValid(arr, n, c, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
        }
        return ans;
    }
};



int main(){
    Solution solution;
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int c = 3;

    cout << solution.maxDistance(arr, n, c) << endl;

    return 0;
}

/*
Explanation

This problem is solved using the Binary Search on Answer approach.
We are given positions of stalls and need to place c cows such that the minimum distance between any two cows is maximized. 
Instead of directly finding the placement, we search for the optimal minimum distance.
First, the stall positions are sorted. This helps in placing cows in a greedy manner from left to right.

We define a search space for the answer:

The minimum possible distance is 1
The maximum possible distance is arr[n-1] - arr[0]

Using binary search, we pick a middle value mid representing the minimum distance and check whether it is possible to place 
all cows such that each cow is at least mid distance apart.

To verify this, we use a greedy approach:

Place the first cow at the first stall
For each next stall, place a cow only if the distance from the last placed cow is at least mid
If we can place all c cows, the configuration is valid

If placing cows is possible for mid, we try to increase the distance by moving low = mid + 1. 
Otherwise, we reduce the distance by setting high = mid - 1.

The largest value of mid for which placement is possible is the final answer.

Why this works

The problem has a monotonic property:

If a distance d is possible, then all distances smaller than d are also possible
If a distance d is not possible, then all larger distances will also not be possible

This makes it suitable for binary search.

Time Complexity
Sorting: O(n log n)
Binary Search: O(log(range))
Validity check: O(n)

Overall: O(n log n + n log(range))

Space Complexity

O(1) (no extra space used)
*/

