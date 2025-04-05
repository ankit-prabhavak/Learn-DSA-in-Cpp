#include <iostream>


using namespace std;


bool linearSearch(int arr[][4], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                return true; // Element found
            }
        }
    }
    return false; // Element not found
}



int main(){
    // Declare a 2D array with 3 rows and 4 columns
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int target = 7; // Element to search for
    bool found = linearSearch(arr, 3, 4, target);
    if (found) {
        cout << "Element " << target << " found in the array." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    

    return 0;
}