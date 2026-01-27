#include <iostream>
#include <vector>
#include <queue>
using namespace std;    


// LeetCode 994. Rotting Oranges

// We will use multisource BFS to solve this problem.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q; // {{i,j},time}
        
        // pushing all source nodes into the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }

        // BFS traversal
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();

            ans=max(ans,time);

            if(i-1>=0 && grid[i-1][j]==1 && visited[i-1][j]==false){ // up
                visited[i-1][j]=true;
               
                q.push({{i-1,j},time+1});
            }

            if(i+1<n && grid[i+1][j]==1 && visited[i+1][j]==false){ // down
                visited[i+1][j]=true;
              
                q.push({{i+1,j},time+1});
            }

            if(j-1>=0 && grid[i][j-1]==1 && visited[i][j-1]==false){ // left
                visited[i][j-1]=true;
               
                q.push({{i,j-1},time+1});
            }

            if(j+1<m && grid[i][j+1]==1 && visited[i][j+1]==false){ // right
                visited[i][j+1]=true;
              
                q.push({{i,j+1},time+1});
            }


        }

        // checking if any fresh orange is left
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    return -1;
                }
            }
        }

        return ans;
    }
    
};