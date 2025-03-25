#include <iostream>
#include <vector>


using namespace std;


class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
    
            int n = arr.size();
            int right  = n-2;
            int left = 1;
            int mid = 0;
            while(left <= right){
                mid = left + (right - left)/2;
                if(arr[mid] > arr[mid-1] &&  arr[mid] >arr[mid+1]){
                    break;
                }
                else if(arr[mid+1] > arr[mid]){
                    left = mid +1;
                }
                else{
                    right = mid - 1;
                }
            }
            return mid;
        }
    };



int main(){

        Solution solution;
        vector<int> arr = {0, 1, 2, 3, 4, 8, 10, 7, 6, 5, 4};

        cout << solution.peakIndexInMountainArray(arr) << endl;

        return 0;
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/


/*
Leetcode 852:

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:

Input: arr = [0,1,0]

Output: 1
*/