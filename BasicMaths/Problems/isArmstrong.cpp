#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;

    // Count the number of digits
    while (n > 0) {
        n /= 10;
        digits++;
    }
 
    n = original; // Reset n to original value

    // Calculate the sum of the digits raised to the power of the number of digits
    while (n > 0) {
        int digit = n % 10;
       // Manual power calculation instead of using pow
       int power = 1;
       for (int i = 0; i < digits; i++) {
           power *= digit;
       }
       
       sum += power;
        n /= 10;
    }

    return sum == original;
}


int main(){
    int n = 153; // Example number

    if (isArmstrong(n)) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }

    return 0;
}