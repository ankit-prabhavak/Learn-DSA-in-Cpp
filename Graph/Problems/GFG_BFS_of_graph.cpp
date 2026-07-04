#include <vector>
#include <queue>
using namespace std;

// This is a C++17 implementation of Breadth First Search (BFS) for a graph represented as an adjacency list.
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                if (!visited[adj[node][i]]) {
                    visited[adj[node][i]] = true;
                    q.push(adj[node][i]);
                }
            }
        }

        return ans;
    }
};