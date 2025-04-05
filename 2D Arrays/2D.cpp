#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Declare a 2D vector with 3 rows and 4 columns
    int rows = 3, cols = 4;

    int arr[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Print the 2D array
    cout << "2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Accessing elements in the 2D array
    cout << "Element at (1, 2): " << arr[1][2] << endl; // Accessing the element at row 1, column 2
    cout << "Element at (2, 3): " << arr[2][3] << endl; // Accessing the element at row 2, column 3

    int arr1[3][4];
    // Initialize the 2D array with user input
    cout << "Enter 12 elements for a 3x4 array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr1[i][j];
        }
    }
    // Print the initialized 2D array
    cout << "Initialized 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }





    return 0;
}
