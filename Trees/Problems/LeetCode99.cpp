#include <iostream>
#include <algorithm>

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
    
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorderTraversal(TreeNode* root) {

        if(!root) return;

        inorderTraversal(root->left);

        if(prev && prev->val > root->val) {
            if(!first) {
                first = prev;
            }
            second = root;
        }

        prev = root;

        inorderTraversal(root->right);

    }
    void recoverTree(TreeNode* root) {
        
        inorderTraversal(root);
        swap(first->val, second->val);
    }
};