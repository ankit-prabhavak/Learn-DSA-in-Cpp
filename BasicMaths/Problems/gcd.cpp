#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::gcd

using namespace std;

int gcd(int a, int b) {
   int gcd = 1; // Initialize gcd to 1

    for(int i = 1; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            gcd =  i;
        }
    }
    return gcd;
}

// Euclidean Algorithm
int gcdEuclideanRecusrsion(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdEuclideanRecusrsion(b, a % b);
}

// Ecuclidean Algorithm Iteration
int gcdEuclideanIteration(int a, int b) {
   
    while(a>0 && b > 0){
        if(a > b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    if(a == 0) return b;
    return a;
}



int main(){
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " using Euclidean Recursion is: " << gcdEuclideanRecusrsion(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " using Euclidean Iteration is: " << gcdEuclideanIteration(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " using STL is: " << __gcd(a, b) << endl; // Using STL function for GC

    return 0;
}