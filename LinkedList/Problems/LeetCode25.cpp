#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // Check if there are at least k nodes to reverse
        while (count < k) {
            if (temp == nullptr) {
                return head; // If less than k nodes, return the head as is
            }
            temp = temp->next;
            count++;
        }

        // Reverse the first k nodes
        ListNode* prev = reverseKGroup(temp, k); // Recursive call to reverse the next k nodes
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next; // Store the next node
            temp->next = prev; // Reverse the current node's pointer
            prev = temp; // Move prev to the current node
            temp = next; // Move to the next node
            count++;
        }

        return prev; // Return the new head of the reversed group
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    int k = 2; // Group size
    ListNode* result = solution.reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(result);

    return 0;
}