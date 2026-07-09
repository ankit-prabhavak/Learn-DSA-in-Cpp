#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// LeetCode 787. Cheapest Flights Within K Stops
// Given n cities and a list of flights, each flight[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights) {

            int u = f[0];
            int v = f[1];
            int wt = f[2];

            adj[u].push_back({v, wt});
        }

        queue<vector<int>> q;

        q.push({0, src, 0});
        // {stops, node, cost}

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        while(!q.empty()) {

            auto curr = q.front();

            q.pop();

            int stops = curr[0];
            int node = curr[1];
            int cost = curr[2];

            if(stops > k)
                continue;

            for(auto &it : adj[node]) {

                int adjNode = it.first;

                int edgeWt = it.second;

                if(cost + edgeWt < dist[adjNode]
                   && stops <= k) {

                    dist[adjNode] = cost + edgeWt;

                    q.push({
                        stops + 1,
                        adjNode,
                        cost + edgeWt
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

/*
Time complexity: O(E + V log V), where E is the number of edges and V is the number of vertices. 
                 In the worst case, we may need to process all edges and vertices in the graph.
                 
Space complexity: O(V + E), where V is the number of vertices and E is the number of edges. 
                            We use an adjacency list to store the graph, which requires O(V + E) space. 
                            Additionally, we use a distance array of size V to store the minimum cost to reach each vertex.
*/