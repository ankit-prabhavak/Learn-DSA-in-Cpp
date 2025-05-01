#include <iostream>
#include <unordered_map>;

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == NULL) return NULL;
            unordered_map<Node*, Node*> nodeMap;

            Node* newHead = new Node(head->val);
            Node* oldTemp = head->next;
            Node* newTemp = newHead;

            while(oldTemp != NULL) {
                Node* copyNode = new Node(oldTemp->val);
                nodeMap[oldTemp] = copyNode;
                newTemp->next = copyNode;

                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }

            oldTemp = head;
            newTemp = newHead;

            while(oldTemp != NULL) {
                if(oldTemp->random != NULL) {
                    newTemp->random = nodeMap[oldTemp->random];
                }
                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }
            // Clean up the map to avoid memory leaks
            for (auto& pair : nodeMap) {
                delete pair.second; // Delete the copied nodes
            }
            return newHead;

        }
    };

    int main() {
        // Create a linked list with random pointers
        Node* head = new Node(7);
        Node* second = new Node(13);
        Node* third = new Node(11);
        Node* fourth = new Node(10);
        Node* fifth = new Node(1);
    
        // Set up next pointers
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
    
        // Set up random pointers
        head->random = NULL;
        second->random = head;
        third->random = fifth;
        fourth->random = second;
        fifth->random = head;
    
        // Call the copyRandomList function
        Solution s;
        Node* copiedList = s.copyRandomList(head);
    
        // Print the original and copied lists
        cout << "Original List:" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << "Node value: " << temp->val;
            if (temp->random) {
                cout << ", Random points to: " << temp->random->val;
            } else {
                cout << ", Random points to: NULL";
            }
            cout << endl;
            temp = temp->next;
        }
    
        cout << "\nCopied List:" << endl;
        temp = copiedList;
        while (temp != NULL) {
            cout << "Node value: " << temp->val;
            if (temp->random) {
                cout << ", Random points to: " << temp->random->val;
            } else {
                cout << ", Random points to: NULL";
            }
            cout << endl;
            temp = temp->next;
        }
    
        return 0;
    }