#include <iostream>
#include <vector>
#include <algorithm> // for reverse function

using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5}; // vector of integers

    cout << "Original vector: ";
    for(int i: v){ // iterate over the vector
        cout << i << " "; // print each element in the vector
    }
    cout << endl; // print a newline

    reverse(v.begin(), v.end()); // reverse the vector in place
    cout << "Reversed vector: ";
    for(int i: v){ // iterate over the reversed vector
        cout << i << " "; // print each element in the reversed vector
    }
    cout << endl; // print a newline

    vector<int> v1 = {1, 2, 3, 4, 5}; // vector of integers

    reverse(v1.begin(), v1.begin() + 3); // reverse the first 3 elements of the vector in place
    cout << "Partially reversed vector: ";
    for(int i: v1){ // iterate over the partially reversed vector
        cout << i << " "; // print each element in the partially reversed vector
    }
    cout << endl; // print a newline

    return 0;
}