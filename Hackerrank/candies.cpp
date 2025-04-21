#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


long candies(int n, vector<int> arr) {
    
    vector<int> candies(n, 1);
    
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }
     for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    
    return accumulate(candies.begin(), candies.end(), 0L);

} 


int main(){
    vector<int> arr = {1, 0, 2}; // Example input
    cout << candies(arr.size(), arr) << endl;
    return 0;
}