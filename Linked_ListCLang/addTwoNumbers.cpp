#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = next;
        }
        return prev;  // Return the new head of the reversed list
    }

    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Reverse both input lists
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(0);  // Dummy node to simplify result construction
        ListNode* p = dummy;
        int carry = 0;

        // Step 2: Add digits one by one
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;  // Carry for the next iteration
            p->next = new ListNode(sum % 10);  // Create a new node with the current digit
            p = p->next;  // Move to the next node in the result list
        }

        // Step 3: Reverse the result list to get the most significant digit first
        return reverse(dummy->next);  // dummy->next is the actual result list
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

int main() {
    // Create the first linked list: 7 -> 2 -> 4 -> 3 (represents 7243)
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    // Create the second linked list: 5 -> 6 -> 4 (represents 564)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    // Add the two numbers
    ListNode* res = s.addTwoNumbers(l1, l2);

    // Print the result linked list: Expected output is 7 -> 8 -> 0 -> 7 (represents 7807)
    printList(res);

    return 0;
}
