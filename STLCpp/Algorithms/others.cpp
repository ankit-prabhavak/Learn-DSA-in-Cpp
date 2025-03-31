#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5}; // vector of integers

    cout<<max(v[0], v[1])<<endl; // find the maximum of two elements in the vector
    cout<<min(v[0], v[1])<<endl; // find the minimum of two elements in the vector

    swap(v[0], v[1]); // swap the first two elements of the vector
    cout << "After swapping: ";
    for(int i: v){ // iterate over the vector
        cout << i << " "; // print each element in the vector
    }
    cout << endl; // print a newline

    cout<<*(max_element(v.begin(), v.end()))<<endl; // find the maximum element in the vector using max_element function
    cout<<*(min_element(v.begin(), v.end()))<<endl; // find the minimum element in the vector using min_element function

    cout<<binary_search(v.begin(), v.end(), 6)<<endl; // check if 6 is present in the vector using binary_search function

    //Count set bits
    int n = 5; // number to count set bits of
    long int n2 = 5; // number to count set bits of
    long long n1 = 5; // number to count set bits of

    cout<<__builtin_popcount(n)<<endl; // count the number of set bits in n using __builtin_popcount function
    cout<<__builtin_popcountl(n2)<<endl; // count the number of set bits in n2 using __builtin_popcountl function
    cout<<__builtin_popcountll(n1)<<endl;// count the number of set bits in n using __builtin_popcountll function


    return 0;
}