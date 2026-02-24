using namespace std;

// Leetcode 1022 | Sum of root to leaf binary numbers

// Definition for a binary tree node.
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
    int answer = 0;

    void dfs(TreeNode* root, int curr) {
        if (!root) return;

        // Build the binary number
        curr = curr * 2 + root->val;

        // If it's a leaf, add to answer
        if (!root->left && !root->right) {
            answer += curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }
};