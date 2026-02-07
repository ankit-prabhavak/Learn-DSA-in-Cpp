#include <vector>
using namespace std;

class Solution {
public:
    // Function to sort the colors using Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) {
        int low = 0;              // Pointer for the next position of 0
        int mid = 0;              // Current element under consideration
        int high = nums.size() - 1; // Pointer for the next position of 2

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

