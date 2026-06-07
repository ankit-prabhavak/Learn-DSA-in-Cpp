#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 Definition for a binary tree node.
**/

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
    vector<int> nums;
    void helpMe(TreeNode* root) {

        if(!root) return;

        nums.push_back(root->val);
        helpMe(root->left);
        helpMe(root->right);

    }
    // vector<int> preorderTraversal(TreeNode* root) {

    //     helpMe(root);
    //     return nums;
        
    // }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* curr = s.top();
            if(curr != NULL) {
                ans.push_back(curr->val);
            }
            s.pop();

            
            if(curr && curr->right != NULL) s.push(curr->right);
            if(curr && curr->left != NULL) s.push(curr->left);
        }

        return ans;
    }
};