#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <list>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    list<pair<int, int>>* adjList; // Adjacency list

    Graph(int V) {
        this->V = V;
        adjList = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // For undirected graph
    }

    void dijkstra(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
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


int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 3);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 4);

    cout << "Dijkstra's Algorithm starting from vertex 0:" << endl;
    g.dijkstra(0);

    return 0;
}




// Dijkstra's Algorithm is a popular algorithm used to find the shortest paths from a source vertex to all other vertices in a graph with non-negative edge weights. 
// The algorithm uses a priority queue to efficiently retrieve the vertex with the smallest distance at each step.

// Time Complexity: O((V + E) log V) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V) for the distance array and the priority queue.

