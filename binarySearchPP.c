//Problem Statement: Search the element in the array if found return index else return its floor value.
#include <stdio.h>

int binarySearch(int arr[],int n, int key)
{
    int l = 0;
    int r = n-1;
    

    int mid;
    while(l <= r){
        mid = l + (r-l)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            l = mid+1;
            if(arr[mid+1]> key)
            return arr[mid];
        }
        else{
            r = mid-1;
            if(arr[mid-1] < key) return arr[mid-1];
        }

    }

    return -1;
}


//Implementation of the logic.
int main(){


    int arr[6] = {1,2,3,5,7,9 };
    int n = 6;

    int ans = binarySearch(arr,n,6);
    printf("%d",ans);




    return 0;
}