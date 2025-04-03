#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of prime numbers less than n using Sieve of Eratosthenes
class Solution {
    public:
        int countPrimes(int n){
            vector<bool> isPrime(n+1, true);
            int count = 0;

            for(int i = 2; i < n; i++){
                if(isPrime[i]){
                    count++;
                    // Mark all multiples of i as non-prime
                    for(int j = 2*i; j < n; j += i){
                        isPrime[j] = false;
                    }
                }
            }
            return count;
        }
};


int main(){
    Solution s;
    int n = 10;
    cout << "Count of prime numbers less than " << n << " is: " << s.countPrimes(n) << endl;
    return 0;
}
// Output: Count of prime numbers less than 10 is: 4