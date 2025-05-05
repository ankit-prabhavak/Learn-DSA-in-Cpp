#include <iostream>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
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
    int moves = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Calculate excess coins in left and right subtrees
        int left_excess = dfs(root->left);
        int right_excess = dfs(root->right);

        // Update total moves
        moves += abs(left_excess) + abs(right_excess);

        // Return excess coins for the current node
        return root->val + left_excess + right_excess - 1;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};

int main() {
    // Create a sample binary tree:
    //        3
    //       / \
    //      0   0
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution mySolution;
    cout << "Minimum moves required: " << mySolution.distributeCoins(root) << endl; // Output: 2

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}