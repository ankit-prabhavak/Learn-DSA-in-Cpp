#include <vector>
using namespace std;

// Hackerrank | Merge Sort : Count Inversions [Hard Level Problem]

// Merge Sort Approach for O(n log n) complexity

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long invCount = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (left.size() - i); // key line
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, int l, int r) {
    long long invCount = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        invCount += mergeSortAndCount(arr, l, m);
        invCount += mergeSortAndCount(arr, m + 1, r);
        invCount += mergeAndCount(arr, l, m, r);
    }
    return invCount;
}

long countInversions(vector<int> arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}



// Bubble Sort Approach O(n²) complexity
long countInversions(vector<int> arr) {
    int n = arr.size();
    long count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

