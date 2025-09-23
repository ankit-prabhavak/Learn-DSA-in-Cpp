#include <iostream>
#include <climits>
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

    TreeNode* prev = nullptr;

   

    int minDiffInBST(TreeNode* root) {

        if(root == NULL) return INT_MAX;
        
        int ans = INT_MAX;
        
        if(root->left) {
           int leftMin = minDiffInBST(root->left);
           ans = min(ans, leftMin);
        }

        if(prev) ans = min(ans, root->val - prev->val);

        prev = root;

        if(root->right) {
           int rightMin = minDiffInBST(root->right);
           ans = min(ans, rightMin);
        }
    }
};