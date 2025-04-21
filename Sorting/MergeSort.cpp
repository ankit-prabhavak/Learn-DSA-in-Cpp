#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &arr, int start, int mid, int end){  //O(n)

    vector<int> temp;

    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
     
    // left 
    while(i <= mid) 
        temp.push_back(arr[i++]);
        
    // right
    while(j <= end) 
        temp.push_back(arr[j++]);
        
    // populate the array with sorted values
    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }

}

void mergeSort(vector<int> &arr, int start, int end){  // O(n*log(n))

    if(start < end){
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

}


int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1); //function call 
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}