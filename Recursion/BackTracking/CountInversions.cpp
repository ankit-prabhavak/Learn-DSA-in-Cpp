#include <iostream>
#include <vector>

// Merges two sorted subarrays and counts cross inversions
long long mergeAndCount(std::vector<int>& arr, std::vector<int>& tempArr, int left, int mid, int right) {
    int i = left;      // Starting index for left subarray
    int j = mid + 1;   // Starting index for right subarray
    int k = left;      // Starting index to be filled in tempArr
    long long invCount = 0;

    // Compare elements from both halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[k] = arr[i];
            i++;
        } else {
            // There are (mid - i + 1) inversions because all remaining elements 
            // in the left subarray are strictly greater than arr[j]
            tempArr[k] = arr[j];
            invCount += (mid - i + 1);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= right) {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted elements back into the original array
    for (int loopVar = left; loopVar <= right; loopVar++) {
        arr[loopVar] = tempArr[loopVar];
    }
        
    return invCount;
}

// Divide-and-conquer function to recursively split the array
long long mergeSortAndCount(std::vector<int>& arr, std::vector<int>& tempArr, int left, int right) {
    long long invCount = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2; // Prevents potential overflow compared to (left + right) / 2

        // Total inversions = left half + right half + cross inversions during merge
        invCount += mergeSortAndCount(arr, tempArr, left, mid);
        invCount += mergeSortAndCount(arr, tempArr, mid + 1, right);
        invCount += mergeAndCount(arr, tempArr, left, mid, right);
    }

    return invCount;
}

int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    
    // Auxiliary vector to assist with the merging process
    std::vector<int> tempArr(n, 0);
    
    long long result = mergeSortAndCount(arr, tempArr, 0, n - 1);
    
    std::cout << "Number of inversions are: " << result << std::endl;
    // Output: Number of inversions are: 3

    return 0;
}
