#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here

        // To store the bottom view nodes
        vector<int> ans;
        
        if (root == NULL) return ans;

        // Map to store the first node at each horizontal distance
        map<int, int> topNodes;

        // Queue to perform level-order traversal
        // Each element in the queue is a pair of a node and its horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
              auto [node, hd] = q.front();
              q.pop();
              
              // Update the map with the current node for this horizontal distance
              topNodes[hd] = node->data;
        
              // Add the left and right children to the queue with updated horizontal distances
              if (node->left) {
                      q.push({node->left, hd - 1});
              }
           
              if (node->right) {
                      q.push({node->right, hd + 1});
              }
        }

       // Print the top view
     
       for (auto [hd, value] : topNodes) {
             ans.push_back(value);
       }

       return ans;
    }
};



int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
             \
              7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}