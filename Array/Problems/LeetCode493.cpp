#include <vector>
using namespace std;

// Brute Force Approach | Just do as it is said
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {

                if(nums[i] > 2LL * nums[j]) {
                    total++;
                }

            }
        }

        return total;
    }
};

// Optimized Approach
class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        for(int i = low; i <= mid; i++) {
            while(j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) return 0;

        int mid = (low + high) / 2;
        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
