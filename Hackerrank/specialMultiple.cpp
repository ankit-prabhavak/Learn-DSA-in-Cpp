#include <iostream>
#include <string>
#include <queue>

using namespace std;


string solve(int n) {
    if(n == 0) return "0";
    
    queue<string>q;
    
    q.push("9");
    while(!q.empty()){
        string temp = q.front();
        q.pop();
        
        long abc = stol(temp);
        if(abc % n == 0) return temp;
        
        q.push(temp+"0");
        q.push(temp+"9");
    }
    
    return "";
}


int main(){

    
    return 0;
}