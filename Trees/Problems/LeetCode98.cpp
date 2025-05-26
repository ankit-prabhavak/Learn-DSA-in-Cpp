#include <vector>
#include <algorithm>
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
    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (!root) return;
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> values;
        inorderTraversal(root, values);

        // Check if the array is sorted in strictly increasing order
        for (int i = 1; i < values.size(); i++) {
            if (values[i] <= values[i - 1]) {
                return false;
            }
        }

        return true;
    }
};