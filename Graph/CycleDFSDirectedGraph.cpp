#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;


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

    // Cycle detection using DFS
    bool isCyclicDFSUtil(int v, vector<bool>& visited, vector<bool>& recStack) { // Time Complexity: O(V + E)
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for (int neighbor : adj[v]) {
                if (!visited[neighbor] && isCyclicDFSUtil(neighbor, visited, recStack))
                    return true;
                else if (recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
    }

    // For other connected components
    bool isCyclicDFS() { // Time Complexity: O(V + E)
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (isCyclicDFSUtil(i, visited, recStack))
                return true;
        }
        return false;
    }

    ~Graph() {
        delete[] adj;
    }

};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // This edge creates a cycle

    // cout << "Graph created with 4 vertices and edges added." << endl;

    if (g.isCyclicDFS())
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}

