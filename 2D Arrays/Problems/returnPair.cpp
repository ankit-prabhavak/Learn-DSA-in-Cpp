#include <iostream>

using namespace std;

pair<int, int> returnPair(int arr[][4], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                return make_pair(i, j); // Return the row and column indices as a pair
            }
        }
    }
    return make_pair(-1, -1); // Return (-1, -1) if the element is not found
}

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int target = 7; // Element to search for
    pair<int, int> result = returnPair(arr, 3, 4, target);
    
    if (result.first != -1) {
        cout << "Element " << target << " found at (" << result.first << ", " << result.second << ")." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
// This code defines a function `returnPair` that searches for a target element in a 2D array and returns its row and column indices as a pair. If the element is not found, it returns (-1, -1). The main function demonstrates how to use this function with a sample 2D array.
// The code is well-structured and easy to understand, making it suitable for educational purposes. It also includes comments to explain the functionality of each part of the code.
