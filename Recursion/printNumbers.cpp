#include <iostream>

using namespace std;


void printNums(int n){
    // Base case
    if(n == 1){
        cout << "1\n";
        return;
    }

    cout << n << " ";
    printNums(n-1);  
}

// recursion relation: time complexity = o(1) + time comlexity of (n-1)

// Example implementation
int main(){
    printNums(100);

    return 0;
}