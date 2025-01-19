#include <iostream>

using namespace std;

// int main(){
//     int n = 4;


//     for(int i = 1; i <=  n; i++){
//      for(int j = 1; j <=  i; j++){
//         cout <<"*";
//         }
//         cout << endl;
//         }
//     return 0;
// }



// int main(){
//     int n = 4;


//     for(int i = 1; i <=  n; i++){
//      for(int j = 1; j <=  i; j++){
//         cout <<i<<" ";
//         }
//         cout << endl;
//         }
//     return 0;
// }


// int main(){
//     int n = 4;
//     char ch = 65;

//     for(int i = 1; i <=  n; i++){
//       for(int j = 1; j <=  i; j++){
//         cout <<ch <<" ";
//         }

//         ch = ch + 1;
//         cout << endl;
//         }

//     return 0;
// }


// int main(){
//     int n = 4;


//     for(int i = 1; i <=  n; i++){
//      for(int j = 1; j <=  i; j++){
//         cout <<j<<" ";
//         }
//         cout << endl;
//         }
//     return 0;
// }


// int main(){
//     int n = 4;


//     for(int i = 1; i <=  n; i++){
//      for(int j = i; j >= 1; j--){
//         cout <<j<<" ";
//         }
//         cout << endl;
//         }
//     return 0;
// }



// int main(){
//     int n = 4;
//     int num = 1;

//     for(int i = 1; i <=  n; i++){
//      for(int j = 1; j <=  i; j++){
//         cout <<num<<" ";
//         num++;
//         }
//         cout << endl;
//         }
//     return 0;
// }




// int main(){
//     int n = 4;


//     for(int i = 1; i <=  n; i++){
      
//       for(int j = 1; j < i; j++)
//          cout<<" ";

//       for(int k = n + 1 - i; k >=1; k--){
//          cout<<n+1-i;
//       }
//         cout << endl;
//         }
//     return 0;
// }





int main(){
    int n = 4;
    for(int i = 1; i <=  n; i++){
     for(int j = 1; j <= n - i; j++)
        cout <<" ";
        
     for(int k = 1 ; k <= i; k++)
         cout<<k<<"";
     
     for(int  l = i - 1; l >= 1; l--)
        cout<<l<<"";

        cout << endl;
        }
    return 0;
}