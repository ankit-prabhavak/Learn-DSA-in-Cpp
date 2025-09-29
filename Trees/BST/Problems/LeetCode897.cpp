#include <iostream>


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
    TreeNode* groot = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);

        groot = insertNode(groot, root->val); // Build the BST

        inorder(root->right);
    }
    
    TreeNode* insertNode(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        if(val < root->val) {
            root->left = insertNode(root->left, val);
        }else if(val > root->val) {
            root->right = insertNode(root->right, val);
        }

        return root;
    }


    TreeNode* increasingBST(TreeNode* root) {

        inorder(root);
        return groot;
        
    }
};