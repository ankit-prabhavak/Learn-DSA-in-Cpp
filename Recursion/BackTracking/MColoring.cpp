#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        for(auto it : adj[node]) {
            if(color[it] == col) return false;
        }
        return true;
    }

    bool solve(int node, int m, vector<int>& color, vector<vector<int>>& adj, int V) {
        // All nodes colored
        if(node == V) return true;

        // Try all colors
        for(int c = 1; c <= m; c++) {
            if(isSafe(node, c, color, adj)) {
                color[node] = c;

                if(solve(node + 1, m, color, adj, V))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int V, vector<vector<int>>& edges, int m) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(V, 0);

        return solve(0, m, color, adj, V);
    }
};

int main() {
    int t;
    cin >> t;  // number of test cases

    while(t--) {
        int V, E, m;
        cin >> V >> E;

        vector<vector<int>> edges(E, vector<int>(2));

        for(int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        cin >> m;

        Solution obj;
        bool ans = obj.graphColoring(V, edges, m);

        if(ans) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}