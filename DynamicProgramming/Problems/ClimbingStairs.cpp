#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;
    int first = 1, second = 1;
    for (int i = 2; i <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main() {
    cout << climbStairs(5) << endl;
    return 0;
}