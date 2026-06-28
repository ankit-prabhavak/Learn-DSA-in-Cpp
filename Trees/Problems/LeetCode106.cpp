#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
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

    unordered_map<int,int> mp;
    int idx;

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int start,
                    int end) {

        if(start > end)
            return NULL;

        int val = postorder[idx--];

        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        // Build right first
        root->right = solve(inorder, postorder, pos + 1, end);

        root->left = solve(inorder, postorder, start, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();

        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        idx = n - 1;

        return solve(inorder, postorder, 0, n - 1);
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the tree. We are visiting each node exactly once.
Space Complexity: O(N) where N is the number of nodes in the tree. This space is used to store the recursive stack and the hash map.
*/

