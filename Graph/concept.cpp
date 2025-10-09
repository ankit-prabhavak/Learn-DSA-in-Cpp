#include <iostream>
#include <list>

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

};

// Main function to demonstrate the Graph class
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


    return 0;
}






