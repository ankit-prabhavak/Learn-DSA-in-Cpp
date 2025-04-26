#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Function to get the prime numbers from 2 to 10^4
vector<int> getPrime() {
    vector<int> prime;
    int lower = 2;
    int upper = 10000;
    for (int i = lower; i < upper; i++) {
        bool isPrime = true;
        for (int j = lower; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            prime.push_back(i);
        }
    }
    return prime;
}

// Function to perform the waiter problem
vector<int> waiter(vector<int> number, int q) {
    vector<int> result, strA, strB;
    int num;
    vector<int> prime = getPrime();  // Get all the prime numbers
    
    // Loop through each prime number
    for (int i = 0; i < q && i < prime.size(); i++) {
        int size = number.size();
        
        // Iterate over the numbers
        for (int j = 0; j < size; j++) {
            num = number.back();
            
            // If the number is divisible by the prime number, move it to strB
            if (num % prime[i] == 0) {
                strB.push_back(num);
                number.pop_back();
            } else {
                // Otherwise, move it to strA
                strA.push_back(num);
                number.pop_back();
            }
        }

        // After processing all numbers, update 'number' to be 'strA' for the next prime
        number = strA;
        strA.clear();

        // Add all numbers in 'strB' to the result
        while (!strB.empty()) {
            result.push_back(strB.back());
            strB.pop_back();
        }
    }
    
    // If there are any remaining numbers in 'number' after all iterations, add them to result
    while (!number.empty()) {
        result.push_back(number.back());
        number.pop_back();
    }

    return result;
}

int main() {
    // Sample input
    vector<int> numbers = {3, 4, 7, 6, 5};
    int q = 4;  // We will consider 4 prime numbers

    // Call the waiter function and get the result
    vector<int> result = waiter(numbers, q);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
