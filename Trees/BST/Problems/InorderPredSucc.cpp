#include <iostream>
#include <climits>

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
    void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key) {
        if (!root) return;

        // If the current node's value is equal to the key
        if (root->val == key) {
            // The predecessor is the maximum value in the left subtree
            if (root->left) {
                TreeNode* temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                pre = temp;
            }

            // The successor is the minimum value in the right subtree
            if (root->right) {
                TreeNode* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                suc = temp;
            }
            return;
        }

        // If the current node's value is greater than the key,
        // then the successor could be this node or in the left subtree
        if (root->val > key) {
            suc = root; // Potential successor
            findPreSuc(root->left, pre, suc, key);
        } else { // If the current node's value is less than the key,
                 // then the predecessor could be this node or in the right subtree
            pre = root; // Potential predecessor
            findPreSuc(root->right, pre, suc, key);
        }
    }

    pair<TreeNode*, TreeNode*> inorderPredecessorSuccessor(TreeNode* root, int key) {
        TreeNode* pre = nullptr;
        TreeNode* suc = nullptr;
        findPreSuc(root, pre, suc, key);
        return {pre, suc};
    }

};


// Example usage
int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->right = new TreeNode(40);

    int key = 10;
    Solution sol;
    auto [pre, suc] = sol.inorderPredecessorSuccessor(root, key);

    if (pre) {
        cout << "Predecessor: " << pre->val << endl;
    } else {
        cout << "Predecessor: NULL" << endl;
    }

    if (suc) {
        cout << "Successor: " << suc->val << endl;
    } else {
        cout << "Successor: NULL" << endl;
    }

    // Clean up memory (not shown here for brevity)

    return 0;
}
