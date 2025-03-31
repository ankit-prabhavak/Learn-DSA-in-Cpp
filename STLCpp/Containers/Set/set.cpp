#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s; // set of integers

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

    cout<<s.size()<<endl; // print size of the set (4)
    cout<<s.max_size()<<endl; // print max size of the set (depends on the system)

    cout<<s.empty()<<endl; // print whether the set is empty or not (0 for false, 1 for true)
    cout<<s.count(1)<<endl; // print count of element 1 in the set (1 if exists, 0 if not)

    cout<<*(s.lower_bound(4))<<endl; // print the first element that is greater than or equal to 4 (4)
    cout<<*(s.lower_bound(5))<<endl; // print the first element that is greater than or equal to 5 (6)
    cout<<*(s.lower_bound(7))<<endl; // 0

    cout<<*(s.upper_bound(4))<<endl; // print the first element that is greater than 4 (6)
    cout<<*(s.upper_bound(5))<<endl; // print the first element that is greater than 5 (6)
    
    return 0;
}