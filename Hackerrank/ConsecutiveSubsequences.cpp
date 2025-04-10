#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


long countSubSequence(int nums[], int n, int k) {
    unordered_map<int, int> Map;
    Map[0] = 1; // To count subarrays that directly divide by k

    long prefixSum = 0;
    long  count = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];
        
        int mod = (prefixSum % k);  
        count += Map[mod];
        Map[mod]++;
    }
    
    return count;
}





int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    
    cin >> t;
    while(t--){
        int n;
        int k;
        cin >> n >> k;
        
        int seq[n];
        for(int i = 0; i < n; i++){
            cin >> seq[i];
        }
        
        long answer = countSubSequence(seq, n, k);
        cout << answer << endl;    
        
    }  
    return 0;
}
