#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;



/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */


// ...existing code...

// Pass 'data' as a parameter to dfs
void dfs(int node, int parent, vector<int> adj[], vector<int>& data, vector<int>& visited, vector<int>& subtreeSum, vector<int>& parentArr) {
    visited[node] = 1;
    subtreeSum[node] = data[node];
    parentArr[node] = parent;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (!visited[child]) {
            dfs(child, node, adj, data, visited, subtreeSum, parentArr);
            subtreeSum[node] += subtreeSum[child];
        }
    }
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int minDiff = INT_MAX;
    int totalSum = 0;
    int n = data.size();
    vector<int> adj[n];
    vector<int> visited(n, 0);
    vector<int> subtreeSum(n, 0);
    vector<int> parent(n, -1);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        totalSum += data[i];
    }6
    // Pass 'data' to dfs
    dfs(0, -1, adj, data, visited, subtreeSum, parent);
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            int diff = abs(totalSum - 2 * subtreeSum[i]);
            minDiff = min(minDiff, diff);
        }
    }
    return minDiff;
    31
}

// ...existing code...




int main() {
    // Example input:
    // Tree with 5 nodes, data = [100, 200, 100, 500, 100, 600]
    // Edges: 1-2, 2-3, 2-5, 4-5, 5-6 (1-based indexing)
    vector<int> data = {100, 200, 100, 500, 100, 600};
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {2, 5},
        {4, 5},
        {5, 6}
    };

    int result = cutTheTree(data, edges);
    cout << "Minimum difference after cutting the tree: " << result << endl;

    return 0;
}