#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void countingSort(vector<int>& arr) {
    
    int maxi = *max_element(arr.begin(), arr.end()); // Take directly the max value if given in the constraints
    
    vector<int> count(maxi+1, 0);

    for(auto& element:arr) {
        count[element] += 1; 
    }

    for(int i = 1; i <= maxi; i++) {
        count[i] += count[i-1];
    }

    vector<int> output(arr.size());

    for(int i = arr.size()-1; i >= 0; i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]] -= 1;
    }
    
    arr = output;

}


// Example Implementation
int main() {

    vector<int> arr = {2, 1, 2, 3, 1, 4, 6, 5, 1, 9};

    //Before Sorting
    cout << "Before sorting: ";
    for(auto& element:arr) {
        cout << element << " ";
    }
    cout <<endl;

    countingSort(arr);

    //After Sorting
    cout << "After Sorting: ";
    for(auto& element:arr) {
        cout << element << " ";
    }
    cout <<endl;

    return 0;
}