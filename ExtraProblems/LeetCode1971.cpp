#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Leetcode 1971 
// Find if path exist in graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

           if(n == 1 || source == destination) return true;

            unordered_map<int, vector<int>> hm;
            vector<bool> visited(n, false);

            for (auto &edge : edges) {
              hm[edge[0]].push_back(edge[1]);
              hm[edge[1]].push_back(edge[0]); // if the graph is undirected (LeetCode 1971 is)

            }
            
            queue<int> q;

            q.push(source);
            visited[source] = true;

            while(!q.empty()) {

                vector<int> values = hm[q.front()];
                q.pop();

                for(auto v: values) {

                    if(!visited[v]) {
                        visited[v] = true;
                        q.push(v);

                        if(v == destination) return true;
                    }

                }

            }

            return false;        
    }
};