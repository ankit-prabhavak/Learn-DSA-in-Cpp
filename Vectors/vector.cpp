#include <iostream>
#include <vector>


using namespace std;

int main(){

    vector<int> v;

    vector<int> v1(5, 10);  // 5 elements with value 10
    vector<int>v2 = {1,2,3,4,5};

    vector<int> v3(v2);    // copy of v2
   
    for(int i = 1; i<=10; i++){
        v.push_back(i);

    }
    
    //Method 1: For  Loop
    // for(int i = 0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    //     }
    
    //Method 2: Range-based for loop
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.emplace_back(10);    // insert at the end of the vector. Creates inplace object.

    cout << "value at 5th index: " << v.at(5) << endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.max_size()<<endl;
    

    v.erase(v.begin()+2);   // erase 3rd element
    v.erase(v.begin()+2, v.begin()+4);   // erase 3rd and 4th element(range)

    v.clear();  // clear the vector
    cout<<v.empty()<<endl;  // check if vector is empty or not

    v.insert(v.begin(), 5); // insert 5 at the beginning

    // erase and clear affect the size of the vector but not the capacity.


    //Iterators
    vector<int> v4 = {1,2,3,4,5};
    vector<int>::iterator it ; // we can also use auto
    for(it = v4.begin(); it!=v4.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //Reverse Iterators
    vector<int>::reverse_iterator it1;  // we can also use auto
    for(it1 = v4.rbegin(); it1!=v4.rend(); it1++){
        cout<<*it1<<" ";
    }
    cout<<endl;
    return 0;
}