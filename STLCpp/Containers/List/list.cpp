#include <iostream>
#include <list>

using namespace std;



int main(){

    list<int> l = {1,2,3,4,5,6,7,8,9,10}; //just like a doubly linked list unlike vector which is like an array

    list<int> l1(5, 10);  // 5 elements with value 10

    l.push_back(6);
    l.push_back(7);
    l.push_front(0);

    for(int i: l){
        cout<<i<<" ";
    }
    cout<<endl;

    l.pop_back();
    l.pop_front();

    l.emplace_back(10);
    l.emplace_front(0);

    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    cout<<l.size()<<endl;
    cout<<l.empty()<<endl;

    l.remove(10);   // removes all the elements with value 10

    // l.clear();  // clear the list
    // rbegin() and rend() are reverse iterators
    // begin() and end() are normal iterators


}