#include <vector>
#include <stack>
using namespace std;

// Leetcode 94: Binary Tree Inorder Traversal

/**
 * Definition for a binary tree node.
**/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive Code

class Solution {
public:
    
    void dfs(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};


// Iterative Code

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr || !st.empty()) {

            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }
};

