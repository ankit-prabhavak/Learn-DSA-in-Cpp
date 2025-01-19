#include <iostream>

using namespace std;

// //simple concepts.
// int main(){
//     int n = 5;
//     int * p= &n;     // p is a pointer to an integer

//     int ** q = &p;  //pointer to pointer.
//     cout << q << endl;
//     cout<<  p << endl;

//     cout << *p << endl;
//     cout << *q << endl;    //dereferencing  q to get the value of p

//     cout  << **q << endl;  //dereferencing  the pointer to pointer to get the value of n

//     //null pointer
//     int * r = NULL;  //used for avoiding garbage memory location.
//     cout << r << endl;

//     int * s;      //a random  garbage value

//     cout<< *s<<endl;  //This will give a garbage  value.


//     return 0;
// }



// pass by reference methods .

void changeA(int * ptr){
    *ptr = 10;
}

void change_A(int  & b){
   b = 20;
}

void change_a(int a){
    a = 30;
}

int main(){
    int a = 5;
   
    change_a(a);  //pass by value.
    cout << a << endl;  //5

    changeA(&a);   //pass by reference using pointers.
    cout << a << endl; // 10

    change_A(a);  //pass by reference using references(alias).
    cout << a << endl; //20

    return 0;
}