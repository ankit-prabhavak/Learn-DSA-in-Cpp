#include <vector>
using namespace std;


class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // Step 1: Check if enough edges exist
        if (connections.size() < n - 1)
            return -1;

        // Step 2: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 3: Count components
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Step 4: Return operations needed
        return components - 1;
    }
};