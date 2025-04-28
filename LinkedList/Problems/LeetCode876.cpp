#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
        ListNode* middleNode(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
    
            // Move fast pointer two steps at a time and slow pointer one step at a time
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            // When fast pointer reaches the end, slow pointer will be at the middle
            return slow;
        }
    };

int main() {
        // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
    
        Solution solution;
        ListNode* middle = solution.middleNode(head);
    
        // Output the value of the middle node
        cout << "Middle node value: " << middle->val << endl;
    
        // Clean up memory (delete nodes)
        delete head->next->next->next->next;
        delete head->next->next->next;
        delete head->next->next;
        delete head->next;
        delete head;
    
        return 0;
}