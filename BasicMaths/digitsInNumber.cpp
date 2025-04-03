#include <iostream>
#include <vector>
#include <cmath> // For log10 function

using namespace std;


void printDigits(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    cout << "Digits in the number: ";
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 12345;
    cout << "Number: " << n << endl;
    printDigits(n);
    
    cout << "Number of digits: " << (int)(log10(n)+1) << endl; // Using log10 to calculate number of digits


    return 0;
}