#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::gcd


using namespace std;

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b); // Using STL function for GCD
}
// Using the formula LCM(a, b) = (a * b) / GCD(a, b)


int main(){
    int a = 12, b = 15;
    cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;
    return 0;
}
// Output: LCM of 12 and 15 is: 60