#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int data) {
        value = data;
        left = right = nullptr;
    }
};

void topView(Node* root) {
    if (root == nullptr) return;

    map<int, int> topViewMap; // horizontal distance -> node value
    queue<pair<Node*, int>> q; // pair of node and its horizontal distance

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();
        Node* node = front.first;
        int hd = front.second;

        // If this horizontal distance is not already present in the map
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->value;
        }

        if (node->left) {
            q.push(make_pair(node->left, hd - 1)); 
        }
        if (node->right) {
            q.push(make_pair(node->right, hd + 1));
        }
    }

    // Print the top view
    for (map<int, int>::iterator it = topViewMap.begin(); it != topViewMap.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
             \
              7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    cout << "Top View of the Binary Tree: ";
    topView(root); // Expected Output: 4 2 1 3 6

    return 0;
}