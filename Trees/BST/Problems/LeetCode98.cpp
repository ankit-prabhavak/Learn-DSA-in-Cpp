#include <iostream>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
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
    bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true; // An empty tree is a valid BST

        // Check if the current node's value violates the min/max constraints
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        // Recursively check the left and right subtrees with updated constraints
        return isValidBSTHelper(root->left, minVal, root->val) &&
               isValidBSTHelper(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};