#include <iostream>

using namespace std;

int factorial(int n){
    // Base case
    if(n == 0 || n == 1)  return 1;

    return n*factorial(n-1);
}


int main(){

    int n = 4;
    cout << "Factorial of " << n << " is: "<< factorial(n)<<endl;

    return 0;
}