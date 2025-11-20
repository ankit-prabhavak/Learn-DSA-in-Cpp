#include <iostream>
#include <climits>
#include <tuple>

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
    long long maxSum = 0;

    // returns tuple: (isBST, minVal, maxVal, sum)
    tuple<bool,long long,long long,long long> helper(TreeNode* root) {
        if (!root) {
            return {true, LLONG_MAX, LLONG_MIN, 0};
        }

        auto [lIsBST, lMin, lMax, lSum] = helper(root->left);
        auto [rIsBST, rMin, rMax, rSum] = helper(root->right);

        // check BST property
        if (lIsBST && rIsBST && lMax < root->val && root->val < rMin) {
            long long sum = lSum + rSum + root->val;
            maxSum = max(maxSum, sum);
            long long mn = min(lMin, (long long)root->val);
            long long mx = max(rMax, (long long)root->val);
            return {true, mn, mx, sum};
        }

        // not a BST: return flag false (min/max/sum values won't be used)
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return (int)maxSum;
    }
};