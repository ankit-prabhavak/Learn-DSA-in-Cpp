#include <iostream>
#include <vector>

using namespace std;

/*
Dutch National Flag Algorithm

The Dutch National Flag Algorithm is a well-known algorithm developed by Edsger Dijkstra, which efficiently sorts an array containing
only three distinct values. The idea is to partition the array into three sections, usually represented by three colors of the Dutch
national flag: red, white, and blue.
In the context of an array, you can think of these three colors as three distinct values, such as 0, 1, and 2, which are commonly used
in problems where you're asked to sort an array containing only these three values.

Problem: Given an array with elements 0, 1, and 2, sort the array using the Dutch National Flag algorithm.
Algorithm Explanation:
You use three pointers: low, mid, and high.
low keeps track of the boundary for elements less than 1 (0's).

mid is used to scan the array.

high keeps track of the boundary for elements greater than 1 (2's).

The idea is to traverse the array with the mid pointer, and swap elements to the appropriate sections:
If the element at mid is 0, it should go to the low section, so you swap it with the element at the low pointer and move both low and
 mid forward.
If the element at mid is 1, it's already in the correct position, so just move mid forward.

If the element at mid is 2, it should go to the high section, so you swap it with the element at the high pointer and move high backward.
*/

class Solution {
    public:
       void sortColors(vector<int>& nums) {  

        
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    

       }



};

// Brute Force Approach
// class Solution {
//     public:
//         void sortColors(vector<int>& nums) {
    
//             int zero  = 0, one = 0, two = 0;
//             for(int i = 0; i < nums.size(); i++){
//                 if(nums[i] == 0)  zero++;
//                 else if(nums[i] == 1) one++;
//                 else two++;
//             }
    
//             int idx = 0;
//             for(int i = 0; i < zero; i++){
//                 nums[idx++] = 0;
//             }
//             for(int i = 0; i < one; i++){
//                 nums[idx++] = 1;
//             }
//             for(int i = 0; i < two; i++){
//                 nums[idx++] = 2;
//             }
            
//         }
//     };



int main(){
    Solution solution;
    vector<int> nums = {2, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1};
    solution.sortColors(nums);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }


    return 0;
}