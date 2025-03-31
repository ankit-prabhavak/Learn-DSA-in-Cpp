#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    multimap<string, int> m; // multimap of integers to characters

    m.insert(make_pair("headphones", 100)); // insert key-value pair (headphones, 100)
    m.insert(make_pair("mouse", 200)); // insert key-value pair (mouse, 200)
    m.insert(make_pair("keyboard", 300)); // insert key-value pair (keyboard, 300)
    m.insert(make_pair("monitor", 400)); // insert key-value pair (monitor, 400)
    m.insert(make_pair("monitor", 500)); // insert key-value pair (monitor, 500)
    m.insert(make_pair("monitor", 600)); // insert key-value pair (monitor, 600)
    m.insert(make_pair("monitor", 700)); // insert key-value pair (monitor, 700)

    m.emplace("tablet", 400); // insert key-value pair (tablet, 400) using emplace function
    m.emplace("tablet", 500); // insert key-value pair (tablet, 500) using emplace function
    m.emplace("tablet", 600); // insert key-value pair (tablet, 600) using emplace function


    for(auto p: m){ // iterate over the multimap
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;


    cout<<m.size()<<endl; // print size of the multimap
    cout<<m.max_size()<<endl; // print max size of the multimap

    cout<<m.empty()<<endl; // print whether the multimap is empty or not

    cout<<m.count("headphones")<<endl; // print count of key "headphones" (1 if exists, 0 if not)

    m.erase(m.find("headphones")); // erase key "headphones" using iterator
    for(auto p: m){ // iterate over the multimap
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;

    m.erase("headphones"); // erase key "headphones"
    for(auto p: m){ // iterate over the multimap
        cout<<p.first<<" "<<p.second<<endl; // print key-value pair
    }
    cout<<endl;

    
    return 0;
}