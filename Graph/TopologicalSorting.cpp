#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Topological Sorting:
// Linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

// Uses: To solve dependency resolution problems, scheduling tasks, etc.

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list representation

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u's list
    }
    // Additional methods for topological sorting would be implemented here
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

    ~Graph() {
        delete[] adj;
    }

};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Topological sorting implementation would go here
    cout << "Topological Sort of the given graph:\n";
    g.topologicalSort();

    return 0;
}

// Time Complexity: O(V + E) for topological sort using DFS
// Space Complexity: O(V) for the stack and visited array
