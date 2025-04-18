#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>


using namespace std;


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Use a set to store obstacles for O(1) access
    set<pair<int, int>> obstacleSet;
    for (const auto& obs : obstacles) {
        obstacleSet.insert({obs[0] - 1, obs[1] - 1}); // Store as 0-indexed
    }

    long sqr = 0;

    // Directions: left, right, up, down, and the four diagonals
    vector<pair<int, int>> directions = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}, 
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (const auto& dir : directions) {
        int x = r_q - 1; // Convert to 0-indexed
        int y = c_q - 1; // Convert to 0-indexed

        while (true) {
            x += dir.first;
            y += dir.second;

            // Check if out of bounds
            if (x < 0 || x >= n || y < 0 || y >= n) {
                break;
            }

            // Check for obstacle
            if (obstacleSet.count({x, y})) {
                break;
            }

            // Count this square as attackable
            sqr++;
        }
    }

    return sqr;
}


int main(){
    int n = 4;
    int k = 0;
    int r_q = 4;
    int c_q = 4;
    vector<vector<int>> obstacles = {{4,4}};
    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}