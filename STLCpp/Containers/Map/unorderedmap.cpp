#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    unordered_map<string, int> m; // unordered_map of integers to characters

    m["headphones"] = 100; // insert key-value pair (headphones, 100)
    m["mouse"] = 200; // insert key-value pair (mouse, 200)

    m.emplace("keyboard", 300); // insert key-value pair (keyboard, 300) using emplace function
    m["monitor"] = 400; // insert key-value pair (monitor, 400)
    m["monitor"] = 500; // insert key-value pair (monitor, 500)
    m["monitor"] = 600; // insert key-value pair (monitor, 600)

    for(auto p: m){ // iterate over the unordered_map
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;

    cout<<m.size()<<endl; // print size of the unordered_map
    cout<<m.max_size()<<endl; // print max size of the unordered_map
    cout<<m.empty()<<endl; // print whether the unordered_map is empty or not
    cout<<m.count("headphones")<<endl; // print count of key "headphones" (1 if exists, 0 if not)
    cout<<m.count("mouse")<<endl; // print count of key "mouse" (

    // print count of key "mouse" (1 if exists, 0 if not)
    m.erase("headphones"); // erase key "headphones"
    for(auto p: m){ // iterate over the unordered_map
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;
    
    return 0;
}