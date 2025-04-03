#include <iostream>
#include <vector>

using namespace std;

// Function to reverse a number
int reverseNumber(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main(){
    int n = 12345; // Example number
    cout << "Original number: " << n << endl;
    cout << "Reversed number: " << reverseNumber(n) << endl;
    
    return 0;
}