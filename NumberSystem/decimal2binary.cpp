#include <iostream>

using namespace std;

void binToDecimal(int n){
    int num = 0;
    int base = 1;
    int temp = n;
    while(temp > 0){
        int last_digit = temp % 10;
        num += last_digit * base;
        base *= 2;
        temp /= 10;
        }
        cout <<"Decimal equivalent of the number is: "<< num << endl;
}


void decToBinary(int n){
     int num = 0;
     int pow = 1;
     while(n > 0){
        int rem = n%2;
        n = n / 2;

        num +=  rem*pow;
        pow *= 10;
     }
    
    cout <<"Binary equivalent of the number is: "<< num << endl;
}

int main(){
    int n = 15;
    int m = 1111;

    decToBinary(n);
    binToDecimal(m);


    return 0;
}