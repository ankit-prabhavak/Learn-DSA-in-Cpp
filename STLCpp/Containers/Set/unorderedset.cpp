#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> s; // unordered set of integers
  
    s.insert(1); // insert 1 into the set
    s.insert(2); // insert 2 into the set
    s.insert(3); // insert 3 into the set
    s.insert(4); // insert 4 into the set

    s.insert(6); // insert 6 into the set

    s.insert(1); // insert 1 into the set again (duplicate, will not be added)
    s.insert(2); // insert 2 into the set again (duplicate, will not be added)


    for(auto i: s){ // iterate over the set
        cout<<i<<" "; // print each element in the set
    }
    cout<<endl; // print a newline

}

// does not have lower_bound and upper_bound functions.