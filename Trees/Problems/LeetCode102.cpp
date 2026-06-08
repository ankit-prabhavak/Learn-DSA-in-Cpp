#include <vector>
#include <queue>
using namespace std;

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

// Leetcode 102: Binary Tree Level Order Traversal
class Solution {
public:
   
    void bfs(TreeNode* root, vector<vector<int>>& ans) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
        }
        
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr) return {};
        
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
    
};