#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

// Hackerrank Connected Components in Graph

vector<int> componentsInGraph(vector<vector<int>> gb) {
    unordered_map<int, vector<int>> adj;

    // Build graph
    for (auto &edge : gb) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, bool> visited;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (auto &p : adj) {
        int node = p.first;

        if (!visited[node]) {
            queue<int> q;
            q.push(node);
            visited[node] = true;

            int count = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                count++;

                for (auto neigh : adj[curr]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }

            // Ignore single nodes
            if (count > 1) {
                mini = min(mini, count);
                maxi = max(maxi, count);
            }
        }
    }

    return {mini, maxi};
}

// Approach 
