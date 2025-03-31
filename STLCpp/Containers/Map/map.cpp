#include <iostream>
#include <map>
#include <string> 

using namespace std;

int main(){
    map<string, int> m; // map of integers to characters

    m["headphones"] = 100; // insert key-value pair (headphones, 100)
    m["mouse"] = 200; // insert key-value pair (mouse, 200)
    m["keyboard"] = 300; // insert key-value pair (keyboard, 300)
    m["monitor"] = 40; // insert key-value pair (monitor, 400)
    
    m.insert(make_pair("camera", 100)); // insert key-value pair (a, 100) using make_pair
    m.insert(pair<string, int>("laptop", 200)); // insert key-value pair (b, 200) using pair function
    m.insert({"printer", 300}); // insert key-value pair (c, 300) using initializer list

    m.emplace("tablet", 400); // insert key-value pair (d, 400) using emplace function

    for(auto p: m){ // iterate over the map
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;
    cout<<m.size()<<endl; // print size of the map
    cout<<m.max_size()<<endl; // print max size of the map
    cout<<m.empty()<<endl; // print whether the map is empty or not
    cout<<m.count("headphones")<<endl; // print count of key "headphones" (1 if exists, 0 if not)
    m.erase("headphones"); // erase key "headphones"

    if(m.find("headphones") == m.end()){ // check if key "headphones" exists
        cout<<"headphones not found"<<endl; // print not found message
    }else{
        cout<<"headphones found"<<endl; // print found message
    }

    
    return 0;
}