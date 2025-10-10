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
    
    // Function to perform BFS traversal from a given source vertex
    void bfs(int start) {
        vector<bool> visited(V, false);
        list<int> queue;

        visited[start] = true;
        queue.push_back(start);

        while (!queue.empty()) {
            int s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (int v : adj[s]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.push_back(v);
                }
            }
        }
        cout << endl;

    }
    // Function to perform DFS traversal from a given source vertex using recursion
    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    } 

    void dfs(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
        cout << endl;
    }
    
    // Dfs traversal using stack
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int v = s.top();
            s.pop();
            cout << v << " ";

            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
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
    

    cout << "BFS traversal starting from vertex 0: ";
    g.bfs(0); // Perform BFS starting from vertex 0

    cout << "DFS traversal (recursive) starting from vertex 0: ";
    g.dfs(0); // Perform DFS starting from vertex 0

    cout << "DFS traversal (using stack) starting from vertex 0: ";
    g.DFS(0); // Perform DFS using stack starting from vertex 0

    return 0;
}




// BFS traversal starting from vertex 0: 0 1 4 2 3
// DFS traversal (recursive) starting from vertex 0: 0 1 2 3 4
// DFS traversal (using stack) starting from vertex 0: 0 4 3 2 1


