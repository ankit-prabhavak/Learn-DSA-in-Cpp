#include <iostream>
#include <vector>

using namespace std;

// Iterative approach
int binarySearch(vector<int> arr, int target){
    int start = 0, end = arr.size() - 1;

    while(start <= end){
        // int mid = (start + end) / 2; 

        int mid = start + (end - start) / 2; // to avoid overflow due to very large numbers optimization

        if(target > arr[mid]){
            start = mid + 1;
        }else if(target < arr[mid]){
            end = mid-1;
        }else{
            return mid;
        }
    }

    return -1;
}

// Recursive approach
int binarySearchRecursive(vector<int> arr, int target, int start, int end){
    if(start <= end){
        int mid = start + (end - start) / 2;

        if(target > arr[mid]){
            return binarySearchRecursive(arr, target, mid + 1, end);
        }else if(target < arr[mid]){
            return binarySearchRecursive(arr, target, start, mid - 1);
        }else{
            return mid;
        }

    }

    return -1;
}

// Example usage
int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 9, 12}; // odd
    int target1 = 9;

    cout << binarySearch(arr1, target1) << endl;

    vector<int> arr2 = { 1, 2, 3, 6, 7, 8};  // even
    int target2 = 6;

    // cout << binarySearch(arr2, target2) << endl;
    cout << binarySearchRecursive(arr2, target2, 0, arr2.size() - 1);

    return 0;
}


/*
Time Complexity:
- Best case: O(1) when the target is the middle element
- Average case: O(log n) when the array is sorted and the target is in the middle 
- Worst case: O(log n) when the array is sorted and the target is not in the array
*/