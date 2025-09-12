#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void kthLevel(Node* root, int k) {
    if (root == nullptr) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int k = 3;
    cout << "Nodes at level " << k << ": ";
    kthLevel(root, k); // Output: 4 5 6
    cout << endl;

    return 0;

}