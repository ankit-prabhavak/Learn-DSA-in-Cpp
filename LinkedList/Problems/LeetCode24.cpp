#include <iostream>

using namespace std;


/*
 Definition for singly-linked list.

*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         // Base case: If the list is empty or has only one node, no swap needed.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize a dummy node to help with head swapping
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;  // Pointer to the node before the pair to be swapped
        ListNode* temp = head;   // Pointer to the current node

        while (temp != NULL && temp->next != NULL) {
            ListNode* n1 = temp;          // First node of the pair
            ListNode* n2 = temp->next;    // Second node of the pair
            
            // Swap the pair
            prev->next = n2;              // Connect previous node to the second node
            n1->next = n2->next;          // Connect first node to the next node after the pair
            n2->next = n1;                // Connect second node to the first node
            
            // Move pointers forward for the next pair
            prev = n1;                    // Move prev to the first node of the current pair
            temp = n1->next;              // Move temp to the next pair's first node
        }

        return dummy->next;  // Return the new head of the list
        
    }
};