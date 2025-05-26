#include <bits/stdc++.h>

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
    int total = 0;

    void inOrder(TreeNode* root, int low, int high) {
        if (root == NULL) return;

        if (root->val > low) {
            inOrder(root->left, low, high);
        }

        if (root->val >= low && root->val <= high) {
            total += root->val;
        }

        if (root->val < high) {
            inOrder(root->right, low, high);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        total = 0; // Reset total for each call
        inOrder(root, low, high);
        return total;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution solution;
    int low = 7, high = 15;
    int result = solution.rangeSumBST(root, low, high);
    
    cout << "Range Sum BST: " << result << endl; // Output should be the sum of values in the range [7, 15]

    return 0;
}