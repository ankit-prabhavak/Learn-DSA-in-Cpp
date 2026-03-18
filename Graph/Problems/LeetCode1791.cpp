#include <vector>
#include <list>
using namespace std;


// Leetcode 1791: Find the center of star graph

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

    int findCenter() {
        for(int i = 0; i < V; i++) {
            if(adj[V].size() == V) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:

    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        Graph g(n);

        for(auto &edge: edges) {
             g.addEdge(edge[0], edge[1]);
        }

       

        
    }
};