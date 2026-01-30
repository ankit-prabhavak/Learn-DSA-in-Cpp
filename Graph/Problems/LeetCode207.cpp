#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 207: Course Schedule
// This is a classic problem of detecting cycles in a directed graph. 
// If there is a cycle, it is impossible to finish all courses.
class Solution {
public:
    bool isCyclicUtil(int src, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& edges) {
        visited[src] = true;
        recStack[src] = true;
        
        // we want to find the correct neighbors from the edges list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            // If the current edge starts from the source node
            if (u == src) {
                if (!visited[v]) {
                    if (isCyclicUtil(v, visited, recStack, edges)) {
                        return true;
                    }
                } else if (recStack[v]) {
                    return true; // Cycle detected
                }
            }
        }

        recStack[src] = false; // Remove the vertex from recursion stack
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);


        for(int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack, prerequisites)) {
                    return false; // Cycle detected, cannot finish all courses
                }
            }
        }


        return true; // No cycles detected, can finish all courses
    }
};