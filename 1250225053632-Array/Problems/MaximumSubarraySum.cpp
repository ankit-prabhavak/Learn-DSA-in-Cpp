#include <iostream>




using namespace std;

int main(){
   int n = 5;
   int arr[5] = {10,-11,4,5,6};
   int sum;
   int max = INT16_MIN;
   
   //worst  case scenario: O(n3)

//    for(int start = 0; start < n; start++){
//     for(int end = start; end < n; end++){
//           sum = 0;
//         for(int  i = start; i <= end; i++){
//             sum += arr[i];
        
//         }
//         if(sum > max){
//             max = sum;
//             }
//     }


//    }

//   cout<<"Maximum  sum of subarray is "<<max;


//Little optimized  version of the above code: O(n2)

for(int start = 0; start < n; start++){
         sum = 0;
    for(int end = start; end < n; end++){
        sum += arr[end];
    }
        if(sum > max){
            max = sum;
            }
   }
   cout<<"Maximum  sum of subarray is "<<max;



// //Kadane's  algorithm: O(n)
// int current_sum = 0;
// int max_sum = INT16_MIN;
// for(int i = 0; i < n; i++){
//     current_sum = current_sum + arr[i];
//     if(current_sum > max_sum)
//         max_sum = current_sum;
        
//     if(current_sum < 0)
//         current_sum = 0;       
// }      
  
//   cout<<"Maximum  sum of subarray is "<<max_sum;


    return  0;

}