#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 0) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};



int main(){
    Solution s;
    int n = 10; // Change this value to generate more or fewer Fibonacci numbers
    cout<<"Fibonacci series: ";
    for(int i=0;i<n;i++){
        cout<<s.fib(i)<<" ";
    }
    cout<<endl;
    
    return 0;
}