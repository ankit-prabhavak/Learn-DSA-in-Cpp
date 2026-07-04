#include <vector>
#include <stack>
using namespace std;

// This is a C++17 implementation of Depth First Search (DFS) for a graph represented as an adjacency list.
class Solution {
  public:
  
    
   vector<int> dfs(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> ans;
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(0);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node]) continue;

        visited[node] = true;
        ans.push_back(node);

        for (int i = adj[node].size() - 1; i >= 0; i--) {
            if (!visited[adj[node][i]])
                st.push(adj[node][i]);
        }
    }

    return ans;
  }
};