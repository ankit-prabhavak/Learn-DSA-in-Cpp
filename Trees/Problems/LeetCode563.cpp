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
    int totalTilt = 0;

    int helpMe(TreeNode* root) {

        if(!root) return 0;

        int leftSum = helpMe(root->left);
        int rightSum = helpMe(root->right);

        int tilt = abs(leftSum - rightSum);
        totalTilt += tilt;

        return leftSum + rightSum + root->val; 
    }
    
    int findTilt(TreeNode* root) {
        
        helpMe(root);
        return totalTilt;
        
    }
};