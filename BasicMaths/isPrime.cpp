#include <iostream>


using namespace std;


string isPrime(int n) {
    if (n <= 1) {
        return "Not Prime";
    }
    for (int i = 2; i*i <= n ; i++) {
        if (n % i == 0) {
            return "Not Prime";
        }
    }
    return "Prime";
}

int countPrime(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime(i) == "Prime") {
            count++;
        }
    }
    return count;
    
}


int main(){
    int num = 17;
    cout << num << " is " << isPrime(num) << endl;

    int a = 10, b = 20;
    cout << "Count of prime numbers between " << a << " and " << b << " is: " << countPrime(a, b) << endl;

    

    return 0;
}