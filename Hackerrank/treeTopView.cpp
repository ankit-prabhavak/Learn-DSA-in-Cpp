#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Definition of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void topView(Node* root) {
    if (root == NULL) return;

    // Map to store the first node at each horizontal distance
    map<int, int> topNodes;

    // Queue to perform level-order traversal
    // Each element in the queue is a pair of a node and its horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // If this horizontal distance is not yet in the map, add it
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = node->data;
        }

        // Add the left and right children to the queue with updated horizontal distances
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view
    for (auto [hd, value] : topNodes) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Top View of the Tree: ";
    topView(root);

    return 0;
}