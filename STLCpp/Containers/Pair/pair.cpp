#include <iostream>
#include <vector>

using namespace std;

int main(){
    pair<int, char> p1; // default constructor
    pair<int, char> p2(1, 'a'); // parameterized constructor
    pair<int, char> p3 = make_pair(2, 'b'); // make_pair function
    pair<int, char> p4 = {3, 'c'}; // initializer list

    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;
    cout << "p3: " << p3.first << ", " << p3.second << endl;
    cout << "p4: " << p4.first << ", " << p4.second << endl;

    pair<int, pair<int, char>> p5; // nested pair
    p5.first = 4;
    p5.second.first = 5;
    p5.second.second = 'd';
    cout << "p5: " << p5.first << ", " << p5.second.first << ", " << p5.second.second << endl;

    vector<pair<int, char>> v; // vector of pairs
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back({6, 'e'}); // push_back with initializer list
    v.emplace_back(7, 'f'); // emplace_back with parameters. Inplace object creation

    cout << "Vector of pairs:" << endl;
    for (auto& p : v) {
        cout << p.first << ", " << p.second << endl;
    }

    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;
    cout << "Max size of vector: " << v.max_size() << endl;

    return 0;
}