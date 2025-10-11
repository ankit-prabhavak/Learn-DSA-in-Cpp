#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


// Graph class definition
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


    // Function to check if there is a cycle in the undirected graph
    bool isCyclicUtil(int v, vector<bool>& visited, int parent) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, v))
                    return true;
            } else if (neighbor != parent) {
                return true; // A back edge detected
            }
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }



};

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

