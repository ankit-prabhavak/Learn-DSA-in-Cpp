#include <iostream>
#include <list>
#include <queue>
#include <vector> // Added missing header

using namespace std;

// Undirected Graph Declaration
class Graph {
    int V; // Number of vertices
    list<int>* adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u's list
        adj[v].push_back(u); // Add u to v's list (for undirected graph)
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool isCycleUndirBFS(int src, vector<int>& vis) {
        queue<pair<int, int>> q;

        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty()) {
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push({v, u});
                    vis[v] = 1;
                } 
                else if (v != parU) {
                    return true; // Found a cycle
                }
            }
        }
        return false; // Added missing return
    }

    bool isCyclic() {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUndirBFS(i, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};


// Implementation of the problem
int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // Print the adjacency list representation of the graph

    if (g.isCyclic())
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
