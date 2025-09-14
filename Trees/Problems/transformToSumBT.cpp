#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to convert tree to sum tree
int sumTree(Node* root) {
    if (root == NULL) return 0;

    int lSum = sumTree(root->left);
    int rSum = sumTree(root->right);

    root->data += lSum + rSum;

    return root->data;
}

// Inorder traversal for printing the tree
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder before sumTree: ";
    inorder(root);
    cout << endl;

    sumTree(root);

    cout << "Inorder after sumTree: ";
    inorder(root);
    cout << endl;

    return 0;
}
