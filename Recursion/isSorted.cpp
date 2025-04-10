#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& arr, int index) {
    // Base case: if we reach the end of the array, it's sorted
    if (index == arr.size() - 1) {
        return true;
    }
    // Check if the current element is less than or equal to the next element
    if (arr[index] > arr[index + 1]) {
        return false; // Not sorted
    }
    // Recursive case: check the rest of the array
    return isSorted(arr, index + 1);
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Change this to test with different arrays
    if (isSorted(arr, 0)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
    return 0;
}