#include <iostream>
#include <vector>

class Solution {
private:
    // STEP 1: Pure counting function using two pointers
    int countPairs(const std::vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            // 2LL prevents integer overflow during multiplication
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    // STEP 2: Pure merging function to combine two sorted halves
    void merge(std::vector<int>& nums, int low, int mid, int high) {
        std::vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // Copy elements back into the original array structure
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // DIVIDE & CONQUER: Coordinates the lifecycle
    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = 0;

        // 1. Divide phase
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);

        // 2. Count cross-boundary pairs *before* altering array order
        count += countPairs(nums, low, mid, high);

        // 3. Conquer phase (sorting)
        merge(nums, low, mid, high);

        return count;
    }

public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, 3, 2, 3, 1};
    
    std::cout << "Number of reverse pairs: " << solver.reversePairs(nums) << std::endl; 
    // Output: 2
    
    return 0;
}
