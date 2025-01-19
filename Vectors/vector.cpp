#include <iostream>
#include <vector>


using namespace std;

int main(){

    vector<int> v;
   
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
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.max_size()<<endl;
    

    return 0;
}