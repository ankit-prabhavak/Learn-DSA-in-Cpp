#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int arr[], int n){ // O(n^2)
    
    for(int i = 0; i < n - 1; i++){
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;

        }

        }

        
        if(!isSwap){  //array is  already sorted.
            return;
        }

   }

}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
         cout << arr[i] << " ";

    cout<<endl;
    return;
}

int main(){
    int arr[] = {1, 5, 7, 8, 9, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr, n);

    bubbleSort(arr, n);

    printArray(arr, n);

    return 0;
}
