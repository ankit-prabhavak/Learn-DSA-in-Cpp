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

// Recursive Approach
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// Iterative approach using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);
        }

        return ans;
    }
};