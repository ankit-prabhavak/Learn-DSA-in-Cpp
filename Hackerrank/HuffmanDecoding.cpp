#include <iostream>
#include <queue>

using namespace std;

// The structure of the node is

typedef struct node {
    int freq;
    char data;
    node * left;
    node * right;
    
} node;

// Solve 
void decode_huff(node * root, string s) {
    node* curr = root;
    for (char c : s) {
        if (c == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // If leaf node, print character and reset to root
        if (!curr->left && !curr->right) {
            cout << curr->data;
            curr = root;
        }
    }
}