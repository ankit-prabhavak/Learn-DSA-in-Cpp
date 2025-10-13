#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
     void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited) {

        visited[i]=true;
        for(int j=0;j<isConnected.size();j++){
            if(i!=j && isConnected[i][j]==true && visited[j]==false){
                dfs(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int cities= isConnected.size();
        vector<bool> visited(cities, false);
        int provinces=0;

        for(int i=0;i<cities;i++){
            if(visited[i]==false){
                dfs(i,isConnected,visited);
                provinces++;
            }
        }

        return provinces;
        
        
    }
   
};