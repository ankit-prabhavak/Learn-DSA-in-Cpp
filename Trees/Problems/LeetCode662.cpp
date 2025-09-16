#include <iostream>
#include<queue>
#include <algorithm>



using namespace std;



/**
Definition for a binary tree node.
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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, unsigned long long>>q;

        q.push({root, 0});

        int maxWidth = 0;

        while(q.size() > 0) {
            int csize = q.size();
            unsigned long long s = q.front().second;
            unsigned long long e = q.back().second;

            maxWidth = max(maxWidth,(int)(e-s+1));

            for(int i = 0; i < csize; i++) {
                auto curr = q.front();

                q.pop();

                if(curr.first->left) q.push({curr.first->left, curr.second*2+1});
                if(curr.first->right) q.push({curr.first->right, curr.second*2+2});


        }

    }


         return maxWidth;     
    }
};