#include <iostream>

using namespace std;

int main(){
    int n = 8;

    for(int i = 1; i <= n; i++ ){
      
      for(int j = 1; j <= n + 1 - i;  j++ )
          cout << " ";
       
      for(int k = 1; k <= 2*i-1; k++){
        if(k == 1)
          cout <<"*";
        else if(k ==  2*i-1)
           cout<<"*";
        else
          cout<<" ";
      }
        cout<<endl;
    }

    int m = n-1;
    for(int i = 1 ;  i <= n - 1; i++){
        for(int  j = 0; j <= i;  j++ )
            cout<<" ";

        for(int k = m*2-1; k>= 1; k--){
            if(k == 1)
            cout<<"*";

            else if(k == m*2-1)
            cout<<"*";

            else
            cout<<" ";

        }    
         m--;
         cout<<endl;
         }

    return 0; 

}