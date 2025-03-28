/*
Problem Statement:
Given an array arr[] and k, where the array represents the boards and each element of the given array represents the length of each board.
k numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. The task is 
to find the minimum time to get this job done by painting all the boards under the constraint that any painter will only paint the continuous
sections of boards. say board [2, 3, 4] or only board [1] or nothing but not board [2, 4, 5].

Examples: 

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be: Painter 1 allocation : [5,10],
Painter 2 allocation : [30], Painter 3 allocation : [20, 15],
Job will be done when all painters finish i.e. at time = max(5 + 10, 30, 20 + 15) = 35
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:

    bool isValid(vector<int>&arr, int n, int m, int maxAllowedTime ){
        int time = 0, painters = 1;

        for(int i : arr){

            if(time + i <= maxAllowedTime){

                time += i;

            }else{
                painters++;
                time = i;
            }
        }

        return painters <= m ;

    }

    int minTime(vector<int>& arr, int n, int m){
        int sum = 0, maxVal = INT16_MIN;
        for(int i : arr) sum += i, maxVal = max(maxVal, i );

        int low = maxVal, high = sum;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(arr, n, m, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;

    }


};


int main(){
    Solution solution;
    vector<int> arr = {5, 10, 30, 20, 15};

    int n = 5, m = 3;

    cout << "minimum time to paint: " << solution.minTime(arr, n, m)  << endl;

    return 0;
}