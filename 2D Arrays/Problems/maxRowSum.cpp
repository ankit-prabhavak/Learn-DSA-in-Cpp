#include <iostream>
#include <climits> // For INT_MIN


using namespace std;

pair<int, int> getMaxRowSum(int arr[][100], int n, int m) {
    int maxSum = INT_MIN;
    int rowIndex = -1;

    for (int i = 0; i < n; i++) {
        int currentRowSum = 0;
        for (int j = 0; j < m; j++) {
            currentRowSum += arr[i][j];
        }
        if (currentRowSum > maxSum) {
            maxSum = currentRowSum;
            rowIndex = i;
        }
    }

    return {maxSum,rowIndex};
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
    pair<int, int> result = getMaxRowSum(arr, n, m);
    cout << "Maximum row sum is " << result.first << " at row index " << result.second << endl;
    cout << "Row elements are: ";
    for (int j = 0; j < m; j++) {
        cout << arr[result.second][j] << " ";
    }
    cout << endl;
    

    return 0;
}
