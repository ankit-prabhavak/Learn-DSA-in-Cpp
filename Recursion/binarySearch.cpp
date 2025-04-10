#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target); // Search in the right half
    } else {
        return binarySearch(arr, left, mid - 1, target); // Search in the left half
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted array
    int target = 7; // Change this to test with different targets
    int result = binarySearch(arr, 0, arr.size() - 1, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    
    return 0;
}