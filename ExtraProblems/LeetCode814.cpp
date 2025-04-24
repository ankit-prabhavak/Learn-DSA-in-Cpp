#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root) {
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);

            if (!root->left && !root->right && root->val == 0) {
                return NULL;
            }
        }

        return root;
    }
};

// Helper function to print the tree in-order
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Create a sample binary tree
    // Input Tree:
    //       1
    //      / \
    //     0   1
    //    / \
    //   0   0
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    Solution s;
    TreeNode* prunedTree = s.pruneTree(root);

    // Print the pruned tree
    cout << "Pruned Tree (In-Order): ";
    printTree(prunedTree);
    cout << endl;

    return 0;
}