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
Time Complexity: O(n log n) or O(log Range) 
*/