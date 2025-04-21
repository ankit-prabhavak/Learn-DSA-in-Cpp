#include <iostream>
#include <vector>

using namespace std;


int truckTour(vector<vector<int>> petrolpumps) {
    int totalPetrol = 0;
    int temp = 0;
    int sid = 0;
    
    
    for(int i=0; i<petrolpumps.size(); i++){
        totalPetrol += (petrolpumps[i][0] -  petrolpumps[i][1]);
        temp += (petrolpumps[i][0] - petrolpumps[i][1]);
        
        if(temp < 0){
            temp = 0;
            sid = i+1;
        }
        
    }
    
    if(totalPetrol < 0 ) return -1;
    
    return sid;
              
    
   }

int main(){
    vector<vector<int>> petrolpumps = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    cout << truckTour(petrolpumps) << endl;
    return 0;
}
