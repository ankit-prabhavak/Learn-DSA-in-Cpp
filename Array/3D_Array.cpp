#include <iostream>

using namespace std;

int main(){
   int cube[2][2][3] = {
{
      {1, 2, 3},
      {4, 5, 6}
},
          {
         {7, 8, 9},
         {10, 11, 12}
          }
           };


       cout<<"v"<<"   "<<"j "<<"j "<<"k"<<endl;
       for(int i=0;i<2;i++)
       {
        for(int  j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout<<cube[i][j][k]<<"   "<<i<<" "<<j<<" "<<k<<" "<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
       }




    return 0;
}