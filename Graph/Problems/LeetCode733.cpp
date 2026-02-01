#include <iostream>
#include <vector>
using namespace std;

// LeetCode 733: Flood Fill
// This problem requires us to change the color of a connected component in a 2D grid.
// We will use DFS to traverse the connected component and change its color.


class Solution {
public:
    void dfsUtil(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
        // Check for out of bounds
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor || image[sr][sc] == newColor  ) {
            return;
        }
       
        // Change the color
        image[sr][sc] = newColor;

        // Explore neighbors (up, down, left, right)
        dfsUtil(image, sr + 1, sc, newColor, originalColor);
        dfsUtil(image, sr - 1, sc, newColor, originalColor);
        dfsUtil(image, sr, sc + 1, newColor, originalColor);
        dfsUtil(image, sr, sc - 1, newColor, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
        dfsUtil(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};