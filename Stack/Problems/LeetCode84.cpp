#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> s;
        
        vector<int> right(n,0);
        vector<int> left(n, 0);

        //Right smaller
        for(int i = n-1; i >=0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();  // if stack is empty, it means there is no smaller element to the right, in this case we take n as the right boundary
            s.push(i);
        }
        
        // Clear the stack for reuse
        while(!s.empty()) {
            s.pop();
        }

        //Left Smaller
        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1: s.top();
            s.push(i);
        }

        int ans = 0;

        for(int i=0; i < n; i++) {
            int width = right[i]-left[i]-1;    // width = right index - left index - 1
            int currArea = heights[i] * width;  
            ans = max(ans, currArea);
        }
     
     return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(heights) << endl; // Output: 10
    return 0;
}