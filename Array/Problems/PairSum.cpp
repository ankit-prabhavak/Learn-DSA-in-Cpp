#include <iostream>


using namespace std;    


void getPair(int arr[], int n, int target){
   int i = 0;
   int j =  n-1;
   int result = -1;

   while(i < j){
    if(arr[j]<target){
        result = arr[i]+arr[j];
        if(result > target)
            j--;
        else if(result <  target)
            i++;
        else{
        cout<<i<<", "<<j<<endl;
        break;
        }
                  
   }
   else
     j--;
   }
   
  
}



//In case sorted array is given and there exist a unique pair.
int main(){
    int n = 4;
    int arr[4] = {2, 7, 11, 15};
    int target = 26;
    getPair(arr, n, target);

    return 0;
}