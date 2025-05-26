#include <bits/stdc++.h>

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }

        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
        
    }
};


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    TreeNode* updatedRoot = solution.insertIntoBST(root, val);

    // Output the updated BST (in-order traversal)
    function<void(TreeNode*)> inOrder = [&](TreeNode* node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    };

    inOrder(updatedRoot);
    cout << endl;

    return 0;
}