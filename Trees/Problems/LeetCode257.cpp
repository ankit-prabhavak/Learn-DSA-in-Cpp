#include <iostream>
#include <vector>

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
        void btPaths(TreeNode* root, string path, vector<string>& final) {
            if (!root) return; // Base case: if the node is null, return
    
            // Append the current node's value to the path
            path += to_string(root->val);
    
            // If it's a leaf node, add the path to the final result
            if (!root->left && !root->right) {
                final.push_back(path);
                return;
            }
    
            // If not a leaf, continue the path with "->"
            path += "->";
    
            // Recur for left and right subtrees
            btPaths(root->left, path, final);
            btPaths(root->right, path, final);
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> final;
            btPaths(root, "", final); // Start with an empty path
            return final;
        }
    };

    int main() {
        // Create a sample binary tree:
        //       1
        //      / \
        //     2   3
        //      \
        //       5
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);
    
        Solution s;
        vector<string> paths = s.binaryTreePaths(root);
    
        // Print all root-to-leaf paths
        cout << "Root-to-Leaf Paths:" << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    
        return 0;
    }


// Second approach using Stack
/*
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;

        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});

        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();

            // If it's a leaf node, add the path to the result
            if (!node->left && !node->right) {
                result.push_back(path);
            }

            // Push right and left children to the stack with updated paths
            if (node->right) {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if (node->left) {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }

        return result;
    }
};

int main() {
    // Create a sample binary tree:
    //       1
    //      / \
    //     2   3
    //      \
    //       5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<string> paths = s.binaryTreePaths(root);

    // Print all root-to-leaf paths
    cout << "Root-to-Leaf Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
*/

