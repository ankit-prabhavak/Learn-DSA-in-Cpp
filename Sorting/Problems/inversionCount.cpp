#include <iostream>
#include <vector>

using namespace std;


int  merge(vector<int> &arr, int start, int mid, int end){  //O(n)
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    int inversionCount = 0;

    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
            inversionCount += (mid - i + 1);
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
    
    return inversionCount;
}

int mergeSort(vector<int> &arr, int start, int end){  // O(n*log(n))

    if(start < end){
        int mid = start + (end - start) / 2;

       int leftCount = mergeSort(arr, start, mid);
       int rightCount =  mergeSort(arr, mid + 1, end);

       int inversion =  merge(arr, start, mid, end);

       return leftCount + rightCount + inversion;
    }

    return 0;
}


int main(){
    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "inversion count : " << ans << endl;

    return 0;
}