#include <iostream>
#include <vector>
using namespace std;

// Leetcode 841: Keys and Rooms

class Solution {
public:
    int n;
    vector<bool>visited;

    void dfs(int currRoom, vector<vector<int>>& rooms){

        if(visited[currRoom] == true) return;
        visited[currRoom] = true;

        for(auto neighbour: rooms[currRoom]){
            dfs(neighbour, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        n = rooms.size();
        visited.resize(n, false);
        dfs(0, rooms);

        for(int i=0; i<n; i++){
            if(visited[i] == false) return false;
        }

        return true;
    }
   
};