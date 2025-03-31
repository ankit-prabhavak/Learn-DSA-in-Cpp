#include <iostream>
#include <vector>
#include <algorithm> // for sort function


using namespace std;

int main(){
    vector<int> v = {5, 2, 8, 1, 4}; // vector of integers
    vector<int> v1 = {5, 2, 8, 1, 4}; // vector of integers

    sort(v.begin(), v.end()); // sort the vector in ascending order
    cout << "Sorted vector in ascending order: ";
    for(int i: v){ // iterate over the sorted vector
        cout << i << " "; // print each element in the sorted vector
    }

    cout << endl; // print a newline
    sort(v1.begin(), v1.end(), greater<int>()); // sort the vector in descending order

    cout << "Sorted vector in descending order: ";
    for(int i: v1){ // iterate over the sorted vector
        cout << i << " "; // print each element in the sorted vector
    }
    cout << endl; // print a newline

    int arr[5] = {5, 2, 8, 1, 4}; // array of integers
    sort(arr, arr + 5); // sort the array in ascending order
    cout << "Sorted array in ascending order: ";
    for(int i: arr){ // iterate over the sorted array
        cout << i << " "; // print each element in the sorted array
    }
    cout << endl; // print a newline
    sort(arr, arr + 5, greater<int>()); // sort the array in descending order
    cout << "Sorted array in descending order: ";
    for(int i: arr){ // iterate over the sorted array
        cout << i << " "; // print each element in the sorted array
    }
    cout << endl; // print a newline
    return 0;
    
}