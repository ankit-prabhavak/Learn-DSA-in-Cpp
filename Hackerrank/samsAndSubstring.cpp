#include <iostream>
#include <string>

using namespace std;


int substrings(string n) {
        long MOD = 1000000007;
    
        long total  = 0;
        long d = 0;
        for(int i = 0; i < n.length(); i++){
            int digit = n[i] - '0';
        
            d = (d*10+digit*(i+1)) % MOD;
            total  = (total + d) % MOD;
        }
    
        return total;
}


int main() {
    
    string n = "1234"; // Example input, you can change it to test with other values
   
    cout << substrings(n) << endl; // Call the substrings function and print the result
    return 0;
}
// This code is a solution to a problem on HackerRank.