#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

// Only for Directed Acyclic Graphs (DAGs)
// Graph class definition for Kahn's Algorithm
class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list representation
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add edge from u to v
    }
    
    void topologicalSortKahn() {
        vector<int> inDegree(V, 0);

        // Calculate in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        // Enqueue all vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            // Decrease in-degree of neighboring vertices
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check if there was a cycle
        if (topoOrder.size() != V) {
            cout << "Graph has a cycle, topological sort not possible." << endl;
            return;
        }

        // Print topological order
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int v : topoOrder) {
            cout << v << " ";
        }
        cout << endl;
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

    ~Graph() {
        delete[] adj;
    }

};


int main() {
    Graph g(6); // Create a graph with 6 vertices

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Kahn's Algorithm implementation would go here to perform topological sort
    g.topologicalSortKahn();

    return 0;
}


// Kahn's Algorithm 
// We do not use visited array here with bfs and dfs because we are using in-degree array to keep track of visited nodes.

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V) for the in-degree array and the queue.

// steps
// 1. Calculate in-degrees of all vertices.
// 2. Enqueue all vertices with in-degree 0.
// 3. While the queue is not empty, dequeue a vertex, add it to the topological order, and decrease the in-degree of its neighbors.
// 4. If any neighbor's in-degree becomes 0, enqueue it.
// 5. If the size of the topological order is not equal to the number of vertices, the graph has a cycle.
// 6. Print the topological order.

// Example Output:
// Topological Sort (Kahn's Algorithm): 5 4 2 3 1 0


