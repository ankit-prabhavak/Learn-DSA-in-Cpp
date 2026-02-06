/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 11: 
//Using brute force approach.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        for(int i = 0; i<height.size(); i++){
            for(int j = i+1; j<height.size(); j++){
                int  water = min(height[i], height[j]) * (j-i);
                maxWater = max(maxWater, water);

            }
        }
        return maxWater;
    }
};

// //Optimized approach using two pointers
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0;
//         int l = 0;
//         int r = height.size() - 1;

//         while(l<r){
//             int width = r-l;
//             int h = min(height[l], height[r]);
//             int cWater = width*h;
//             maxWater = max(cWater, maxWater);

//             height[l]<height[r]?l++:r--;
//         }

    
//         return maxWater; 
//     }
// };

int main(){
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8};
    cout << solution.maxArea(height) << endl;

    return 0;
}