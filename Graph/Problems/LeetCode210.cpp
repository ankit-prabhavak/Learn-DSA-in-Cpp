#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// LeetCode 210: Course Schedule II
// This problem requires us to return the order of courses to finish all courses given the prerequisites.
// We will use DFS to perform a topological sort on the directed graph formed by the courses and their prerequisites.

class Solution {
public:
      // Cycle Detection Utility Function
      bool isCyclicUtil(int src, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& edges) {
        visited[src] = true;
        recStack[src] = true;
        
        // we want to find the correct neighbors from the edges list
        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];
            
            // If the current edge starts from the source node
            if (u == src) {
                if (!visited[v]) {
                    if (isCyclicUtil(v, visited, recStack, edges)) {
                        return true; // Cycle detected
                    }
                } else if (recStack[v]) {
                    return true; // Cycle detected(back edge)
                }
            }
        }

        recStack[src] = false; // Remove the vertex from recursion stack
        return false;
    }
    
    // Topological Sort Utility Function
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& edges) {
        visited[v] = true;

        for (int i = 0; i < edges.size(); i++) {
            int neigh = edges[i][0];
            int u = edges[i][1];

            if (u == v && !visited[neigh]) {
                topologicalSortUtil(neigh, visited, Stack, edges);
            }
        }
        Stack.push(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        // First, check for cycles in the graph
        for(int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack, prerequisites)) {
                    return {}; // Cycle detected, cannot finish all courses, return empty list
                }
            }
        }

        // If no cycles, perform topological sort
        visited.assign(numCourses, false);  // Reset visited for topological sort
        stack<int> Stack;   // Stack to store the topological order in reverse
        vector<int> result;
        
        // Perform DFS for topological sorting for each unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack, prerequisites);
            }
        }
        
        // Populating result from stack in reverse order
        while (!Stack.empty()) {
            result.push_back(Stack.top());
            Stack.pop();
        }

        return result;  
    }
};