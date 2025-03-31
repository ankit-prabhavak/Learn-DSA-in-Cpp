#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; // custom comparator to sort based on the second element of the pair
}

int main(){
    vector<pair<int, int>> v = {{5, 2}, {8, 1}, {4, 3}}; // vector of pairs of integers

    sort(v.begin(), v.end()); // sort the vector in ascending order based on the first element of the pair
    cout << "Sorted vector in ascending order based on first element: ";
    for (auto it = v.begin(); it != v.end(); ++it) { // iterate over the sorted vector
        cout << "(" << it->first << ", " << it->second << ") "; // print each pair in the sorted vector
    }
    cout << endl; // print a newline

    sort(v.begin(), v.end(), compare); // sort the vector in ascending order based on the second element of the pair using custom comparator
    cout << "Sorted vector in ascending order based on second element: ";
    for (auto it = v.begin(); it != v.end(); ++it) { // iterate over the sorted vector
        cout << "(" << it->first << ", " << it->second << ") "; // print each pair in the sorted vector
    }
    cout << endl; // print a newline

    return 0;
}