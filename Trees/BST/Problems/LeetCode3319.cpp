#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

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

// Simpler approach without std::function: single post-order traversal that
// returns (isPerfect, size) and collects sizes of perfect subtrees.
class Solution {
public:
    // helper returns pair<isPerfect, size> and pushes sizes of perfect subtrees into vec
    pair<bool,int> isPerfectAndSize(TreeNode* node, vector<int>& vec) {
        if (!node) return make_pair(true, 0);

        pair<bool,int> L = isPerfectAndSize(node->left, vec);
        pair<bool,int> R = isPerfectAndSize(node->right, vec);

        int sz = L.second + R.second + 1;
        bool isPerfect = L.first && R.first && (L.second == R.second);
        if (isPerfect) vec.push_back(sz);
        return make_pair(isPerfect, sz);
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> perfectSizes;
        isPerfectAndSize(root, perfectSizes);

        sort(perfectSizes.rbegin(), perfectSizes.rend());
        if (k <= (int)perfectSizes.size()) return perfectSizes[k-1];
        return -1;
    }
};