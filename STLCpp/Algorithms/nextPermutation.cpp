#include <iostream>
#include <vector>
#include <algorithm> // for next_permutation function
#include <string> // for string class

using namespace std;

int main(){
    string str = "abc"; // string to find the next permutation of
    cout << "Original string: " << str << endl; // print the original string

    next_permutation(str.begin(), str.end()); // find the next permutation of the string in place
    cout << "Next permutation: " << str << endl; // print the next permutation of the string

    prev_permutation(str.begin(), str.end()); // find the previous permutation of the string in place
    cout << "Previous permutation: " << str << endl; // print the previous permutation of the string

    return 0;
}