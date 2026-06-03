#include <iostream>
#include <vector>
using namespace std;


// Leetcode 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

       int totalPetrol = 0;
       int temp = 0;
       int sidx = 0;
    
    
       for(int i=0; i<gas.size(); i++){
             totalPetrol += (gas[i] -  cost[i]);
             temp += (gas[i] - cost[i]);
        
             if(temp < 0){
                    temp = 0;
                    sidx = i+1;
             }
        
        }
    
    if(totalPetrol < 0 ) return -1;
    
    return sidx;
        
    }
};