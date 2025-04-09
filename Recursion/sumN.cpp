#include <iostream>

using namespace std;

int sumN(int n){
    // Base case
    if(n == 1){
        return 1;
    }
    
    return n + sumN(n-1);
}


int main(){
    int n = 10;
    cout << "Sum: "<< sumN(n) << endl;
    return 0;
}