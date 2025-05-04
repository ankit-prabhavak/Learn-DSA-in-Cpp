#include <iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr; // If the head is null, return null

        Node* current = head;
        while (current) {
            if (current->child) {
                Node* next = current->next;

                // Recursively flatten the child list
                current->next = flatten(current->child);
                current->next->prev = current; // Set the previous pointer of the child list's head
                current->child = nullptr; // Set the child pointer to null

                // Find the last node of the child list
                Node* temp = current;
                while (temp->next) {
                    temp = temp->next;
                }

                // Connect the last node of the child list to the next node
                if (next) {
                    temp->next = next;
                    next->prev = temp;
                }
            }
            current = current->next;
        }

        return head; // Return the head of the flattened list
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a sample multilevel doubly linked list:
    // 1 - 2 - 3
    //     |
    //     4 - 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    Solution solution;
    Node* flattenedList = solution.flatten(head);

    // Print the flattened list
    cout << "Flattened List: ";
    printList(flattenedList);

    return 0;
}