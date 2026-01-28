#include <iostream>

using namespace std;


//Using Moore's  Voting Algorithm.
int majorityElement(int arr[], int n){
        int freq = 0;
        int  candidate = -1;
        for(int i = 0; i < n; i++){
            if(freq == 0)
                candidate = arr[i];
            if(arr[i] == candidate)
                 freq++;
            else
                freq--;
        } 

        //In case there is no majority element is not  present in the array
        // int count = 0;
        // for(int i = 0; i < n; i++){
        //     if(arr[i] == candidate)
        //     count++;
        //     }
        //     if(count > n/2)
        //     return candidate;
        //     else
        //     return -1;

    return candidate;
}




//Majority  Element always  exist in the array.
int main(){
    int  arr[] = {1, 2, 3, 2, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = majorityElement(arr, n);
    cout<<"Required majority element: "<<ans<<endl;

    return 0;
}

/*
Dry Run 
-------
Input: [1 2 3 2 2 4]

Iteration 1: i = 0, freq = 0 -> candidate = 1, freq = 1

Iteration 2: i = 1, arr[i] = 2 != candidate -> freq = 0

Iteration 3: i = 2, freq = 0 -> candidate = 3, freq = 1

Iteration 4: i = 3, arr[i] = 2 != candidate -> freq = 0

Iteration 5: i = 4, freq = 0 -> candidate = 2, freq = 1

Iteration 6: i = 5, arr[i] = 4 != candidate -> freq = 0

Output: 2 (majority element which is our last candidate)
*/