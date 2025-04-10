#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
    int sansaXor(vector<int>&arr) {
        int n = arr.size();
        
        if(n % 2 == 0) return 0;
        
        int result = arr[0];
        
        for(int i= 1; i <n; i++){
            
            if(i%2 == 0){
                result ^= arr[i];
            }
            
        }
        
        return result;
    
    }
};


int main(){
    Solution sol;
    vector<int>arr = {1, 2, 3};

    cout << "Answer: " << sol.sansaXor(arr) << endl;

    return 0;
}