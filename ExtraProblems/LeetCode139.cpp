#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

       int totalPetrol = 0;   // overall fuel balance
       int temp = 0;          // temporary tank balance
       int sidx = 0;          // candidate starting index
    
       for(int i=0; i<gas.size(); i++){
             totalPetrol += (gas[i] - cost[i]);
             temp += (gas[i] - cost[i]);
        
             // if tank goes negative, reset
             if(temp < 0){
                    temp = 0;
                    sidx = i+1;
             }
        }
    
        if(totalPetrol < 0 ) return -1;
        return sidx;
    }
};