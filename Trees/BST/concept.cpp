#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int data) {
        value = data;
        left = right = nullptr;
    }
};

class Tree {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->value) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return nullptr;
        if (key < node->value) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->value) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void levelOrder(Node* node) {
        if (node == nullptr) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->value << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

public:
    Tree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    void levelOrder() {
        levelOrder(root);
        cout << endl;
    }
};

int main() {
    Tree BST;

    // Insert values
    BST.insert(10);
    BST.insert(5);
    BST.insert(15);
    BST.insert(3);
    BST.insert(7);
    BST.insert(12);
    BST.insert(18);

    cout << "Inorder Traversal: ";
    BST.inorder();

    cout << "Preorder Traversal: ";
    BST.preorder();

    cout << "Postorder Traversal: ";
    BST.postorder();

    cout << "Level Order Traversal: ";
    BST.levelOrder();

    // Delete a value
    BST.deleteValue(15);
    cout << "After deleting 15, Level Order Traversal: ";
    BST.levelOrder();

    return 0;
}

