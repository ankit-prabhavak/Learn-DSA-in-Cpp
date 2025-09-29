#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper structure to store info for each subtree
struct Info {
    bool isBST;
    int size;   // size of subtree
    int minVal;
    int maxVal;
    
    Info(bool bst, int sz, int mn, int mx) 
        : isBST(bst), size(sz), minVal(mn), maxVal(mx) {}
};

class Solution {
public:
    int maxBSTSize = 0;

    Info largestBSTHelper(TreeNode* root) {
        if (!root) {
            return Info(true, 0, INT_MAX, INT_MIN);
        }

        // Recursively get info about left & right subtrees
        Info leftInfo = largestBSTHelper(root->left);
        Info rightInfo = largestBSTHelper(root->right);

        // Current node is BST if:
        // 1. Left subtree is BST
        // 2. Right subtree is BST
        // 3. root->val > max in left subtree
        // 4. root->val < min in right subtree
        if (leftInfo.isBST && rightInfo.isBST &&
            root->val > leftInfo.maxVal && root->val < rightInfo.minVal) {
            
            int currSize = leftInfo.size + rightInfo.size + 1;
            maxBSTSize = max(maxBSTSize, currSize);

            return Info(true, currSize, 
                        min(root->val, leftInfo.minVal), 
                        max(root->val, rightInfo.maxVal));
        }

        // If not BST, return false with max size of children
        return Info(false, max(leftInfo.size, rightInfo.size), 0, 0);
    }

    int largestBSTSubtree(TreeNode* root) {
        largestBSTHelper(root);
        return maxBSTSize;
    }
};

// -------------------------------
// Example usage
// -------------------------------
int main() {
    /*
         10
        /  \
       5   15
      / \    \
     1   8    7
     
     The largest BST subtree is:
           5
          / \
         1   8
     Size = 3
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Largest BST size: " << sol.largestBSTSubtree(root) << endl;
    return 0;
}
