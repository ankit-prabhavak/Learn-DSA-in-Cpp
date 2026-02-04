#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <list>
using namespace std;

// Bellman-Ford Algorithm Implementation
// This algorithm finds the shortest paths from a single source vertex to all other vertices in a weighted graph.
// It can handle graphs with negative weight edges.
// Time Complexity: O(V * E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V) for storing distances.
// It cannot handle graphs with negative weight cycles.

class Graph {
private:
    int V; // Number of vertices
    list<pair<int, int>>* adjList; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adjList = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (auto& neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < V; u++) {
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }

        // Print the shortest distances from the source
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t" << dist[i] << endl;
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ":";
            for (auto& neighbor : adjList[i]) {
                cout << " -> (" << neighbor.first << ", " << neighbor.second << ")";
            }
            cout << endl;
        }
    }


};

// Example usage
int main() {
    
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
    cout << "Bellman-Ford Algorithm starting from vertex 0:" << endl;
    g.bellmanFord(0);

    return 0;
}