#include <iostream>

using namespace std;

void revArray(int arr[], int n){
    int start = 0, end = n-1;

    while(start < end ){
        swap(arr[start], arr[end]);
        start++;
        end--;

    }

}

// void swapp(int *a, int *b){
//    int temp  = *a;
//    *a  = *b;
//    *b = temp;
// }


int main(){
    int arr[] = {4 ,2 ,8, 6, 3, 2};
    int n = 6;

    revArray(arr, n);
//  int start = 0, end = n-1;

//     while(start < end ){
//         swapp(&arr[start], &arr[end]);
//         start++;
//         end--;

//     }



    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}