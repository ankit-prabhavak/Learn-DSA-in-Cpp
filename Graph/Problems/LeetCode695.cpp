#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Leetcode 695: Max Area of Island

class Solution {
public:
     
    int getIslandSize(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        
        int count = 0;
        queue<pair<int, int>> q;
        
        q.push({x, y});
        visited[x][y] = 1;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            count += 1;
            
            // up
            if (i-1 >= 0 && visited[i-1][j] == 0 && grid[i-1][j] == 1) {
                q.push({i-1, j});
                visited[i-1][j] = 1;
            }
            // down
            if (i+1 < grid.size() && visited[i+1][j] == 0 && grid[i+1][j] == 1) {
                q.push({i+1, j});
                visited[i+1][j] = 1;
            }
            // left
           if (j-1 >= 0 && visited[i][j-1] == 0 && grid[i][j-1] == 1) {
                q.push({i, j-1});
                visited[i][j-1] = 1;
            }
            // right
           if (j+1 < grid[0].size() && visited[i][j+1] == 0 && grid[i][j+1] == 1) {
                q.push({i, j+1});
                visited[i][j+1] = 1;
            }

        }

        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(visited[i][j] == 0 && grid[i][j] == 1) {
                    count = max(count, getIslandSize(grid, visited, i, j)); 
                }
            }
        }
        
        // Max Area
        return count;
        
    }
};