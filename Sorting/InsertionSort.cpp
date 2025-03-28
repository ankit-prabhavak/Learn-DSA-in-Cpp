#include <iostream>
#include <vector>

using namespace std;


void insertionSort(int arr[], int n){

    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int prevIdx = i - 1;
        while (prevIdx >= 0 && arr[prevIdx] > current) {
            arr[prevIdx + 1] = arr[prevIdx];
            prevIdx--;
            }
            arr[prevIdx + 1] = current;
    }
    
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

}



int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;

}

