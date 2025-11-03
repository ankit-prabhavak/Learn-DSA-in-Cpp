#include <iostream>
#include <queue>

using namespace std;

/*
Definition for a binary tree node.
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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<pair<TreeNode*, TreeNode*>> q; // pair of node and its parent
        q.push({root, nullptr});

        while (!q.empty()) {
            int size = q.size();
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) parentX = parent;
                if (node->val == y) parentY = parent;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // After processing the current level, check if we found both nodes
            if (parentX && parentY) {
                return parentX != parentY; // They are cousins if parents are different
            }
            if (parentX || parentY) {
                return false; // Found one node but not the other at the same level
            }
        }
        
    }
};