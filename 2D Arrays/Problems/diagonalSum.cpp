#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(int arr[][100], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) { // Primary diagonal
                sum += arr[i][j];
            }
            if (i + j == n - 1) { // Secondary diagonal
                sum += arr[i][j];
            }
        }
    }
    
    // If n is odd, subtract the center element as it was counted twice
    if (n % 2 == 1) {
        sum -= arr[n / 2][n / 2];
    }

    return sum;
}

//O(n) optimized version
int optimizedDiagonalSum(int arr[][100], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i]; // Primary diagonal
        if (i != n - 1 - i) { // Avoid double counting the center element in odd-sized matrix
            sum += arr[i][n - 1 - i]; // Secondary diagonal
        }
    }
    return sum;
}


int main(){
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    int arr[100][100]; // Assuming a maximum size of 100x100 for simplicity
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int result = diagonalSum(arr, n, m);
    cout << "Diagonal sum is " << result << endl;
    cout << "Diagonal elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][i] << " "; // Primary diagonal elements
    }
    cout << endl;
    cout << "Secondary diagonal elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][n - 1 - i] << " "; // Secondary diagonal elements
    }
    cout << endl;
    
    cout << "Optimized diagonal sum is " << optimizedDiagonalSum(arr, n, m) << endl;
    cout << "Optimized diagonal elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][i] << " "; // Primary diagonal elements
    }
    cout << endl;
    cout << "Secondary diagonal elements are: ";
    for (int i = 0; i < n; i++) {
        if (i != n - 1 - i) { // Avoid double counting the center element in odd-sized matrix
            cout << arr[i][n - 1 - i] << " "; // Secondary diagonal elements
        }
    }
    cout << endl;

    //formula  j = n - 1 - i
    cout << "Note: If the matrix is odd-sized, the center element is counted twice." << endl;
    cout << "To avoid double counting, you can subtract the center element if n is odd." << endl;

    return 0;
}