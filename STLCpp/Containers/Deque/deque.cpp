#include <iostream>
#include <deque>

using namespace std;

int main(){

    deque<int> d;

    deque<int> d1(5, 10);  // 5 elements with value 10
    deque<int>d2 = {1,2,3,4,5};

    deque<int> d3(d2);    // copy of d2
   
    for(int i = 1; i<=10; i++){
        d.push_back(i);

    }
    
    //Method 1: For  Loop
    // for(int i = 0; i<d.size(); i++){
    //     cout<<d[i]<<" ";
    //     }
    
    //Method 2: Range-based for loop
    for(int i: d){
        cout<<i<<" ";
    }
    cout<<endl;
     
    d.push_back(6);
    d.push_back(7);
    d.push_front(0);
    d.push_front(1);
    d.push_front(2);
    
    d.emplace_back(10);   
    d.emplace_front(0);
    d.emplace_front(1);
    d.emplace_front(2);

    d.pop_front();
    d.pop_front(); 
    d.pop_back();
    d.pop_back();



    cout << "value at 5th index: " << d.at(5) << endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.pop_back();
    cout<<d.size()<<endl;
    cout<<d.max_size()<<endl;
    

    d.erase(d.begin()+2);   // erase 3rd element
    d.erase(d.begin()+2, d.begin()+4);   // erase 3rd and 4th element(range)

    d.clear();  // clear the deque
    cout<<d.empty()<<endl;  // check if deque is empty or not

    d.insert(d.begin(), 5); // insert 5 at the beginning

    // erase and clear affect the size of the deque but not the capacity.


    //Iterators
    deque<int> d4 = {1,2,3,4,5};
    deque<int>::iterator it ; // we can also use auto
    for(it = d4.begin(); it!=d4.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}