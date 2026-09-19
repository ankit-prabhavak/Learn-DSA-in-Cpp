#include <iostream>
#include <vector>
#include <string>

using namespace std;


// void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans) {  //vector<vector<bool>> &visited
//     if(r < 0 || c < 0 || r >= mat.size() || c >= mat[0].size() || mat[r][c] == 0 || mat[r][c] == -1) { // visted[r][c] == true
//         return;
//     }

//     if(r == mat.size() - 1 && c == mat[0].size() - 1){
//         ans.push_back(path);
//         return;
//     }
    
//     // visited[r][c] = true;
//     mat[r][c] = -1;

//     // helper(mat, r+1, c, path+"D", ans, visited); // down
//     // helper(mat, r-1, c, path+"U", ans, visited); // up
//     // helper(mat, r, c-1, path+"L", ans, visited); // left
//     // helper(mat, r, c+1, path+"R", ans, visited); // right

//     helper(mat, r+1, c, path+"D", ans); // down
//     helper(mat, r-1, c, path+"U", ans); // up
//     helper(mat, r, c-1, path+"L", ans); // left
//     helper(mat, r, c+1, path+"R", ans); // right

//     // visited[r][c] = false;
//     mat[r][c] = 1;
// }

// // Function to find all paths from top left to bottom right of a matrix
// vector<string> findPath(vector<vector<int>> &mat){
//     // vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
//     vector<string> ans;
//     string path = "";

//     // helper(mat, 0, 0, path, ans, visited);
//     helper(mat, 0, 0, path, ans);
//     return ans;
// }

// int main(){
//     vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    
//     vector<string> ans = findPath(mat);
//     for (const auto& str : ans) {
//         cout << str << endl;
//     }

//     return 0;
// }

// Optimized Approach
class Solution {
public:

    void helper(vector<vector<int>>& maze,
                int row,
                int col,
                string path,
                vector<string>& ans,
                vector<vector<int>>& vis) {

        int n = maze.size();

        // Destination reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        // Down, Left, Right, Up
        vector<int> dr = {1, 0, 0, -1};
        vector<int> dc = {0, -1, 1, 0};
        vector<char> dir = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            // Check valid and unvisited cell
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                maze[nr][nc] == 1 &&
                !vis[nr][nc]) {

                vis[nr][nc] = 1;

                helper(maze, nr, nc,
                       path + dir[i],
                       ans, vis);

                // Backtrack
                vis[nr][nc] = 0;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        vis[0][0] = 1;

        helper(maze, 0, 0, "", ans, vis);

        return ans;
    }
};