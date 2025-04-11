#include <iostream>
#include <vector>

using namespace std;

void printSubarray(vector<int>&arr, vector<int>&subarr, int i){
    if(i == arr.size()){
        cout << "{ ";
        for(int j = 0; j < subarr.size(); j++){
            cout << subarr[j] << " ";
        }
        cout << "}" << endl;
        return;
    }

    //Include the current element in the subarray
    subarr.push_back(arr[i]);
    printSubarray(arr, subarr, i + 1);

    //Exclude the current element from the subarray
    subarr.pop_back();
    printSubarray(arr, subarr, i + 1);
   
}


int main(){
    vector<int> arr = {1, 2, 3};
  
    vector<int> subarr;

    printSubarray(arr, subarr, 0);


    return 0;
}