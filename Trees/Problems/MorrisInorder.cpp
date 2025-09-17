#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit current node
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find predecessor (rightmost node in left subtree)
                TreeNode* predecessor = curr->left;
                while (predecessor->right != NULL && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL) {
                    // Make thread
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    // Break thread and visit current
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Example: build a small binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    vector<int> result = s.inorder(root);

    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
