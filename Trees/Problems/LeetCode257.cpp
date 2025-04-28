#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {

         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        void btPaths(TreeNode* root, string path, vector<string>& final) {
            if (!root) return; // Base case: if the node is null, return
    
            // Append the current node's value to the path
            path += to_string(root->val);
    
            // If it's a leaf node, add the path to the final result
            if (!root->left && !root->right) {
                final.push_back(path);
                return;
            }
    
            // If not a leaf, continue the path with "->"
            path += "->";
    
            // Recur for left and right subtrees
            btPaths(root->left, path, final);
            btPaths(root->right, path, final);
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> final;
            btPaths(root, "", final); // Start with an empty path
            return final;
        }
    };

