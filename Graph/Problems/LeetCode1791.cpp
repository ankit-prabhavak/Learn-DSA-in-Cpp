#include <vector>
#include <list>
using namespace std;


// Leetcode 1791: Find the center of star graph

int findCenter(vector<vector<int>>& edges) {
    if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    return edges[0][1];
}

