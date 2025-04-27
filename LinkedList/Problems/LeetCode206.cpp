#include <iostream>

using namespace std;


struct ListNode {
        int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr != nullptr) {
                ListNode* nextNode = curr->next; // Save next node
                curr->next = prev; // Reverse the pointer
                prev = curr; // Move prev forward
                curr = nextNode; // Move curr forward
            }
            return prev;
        }
    };

int main() {
        // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
    
        // Print the original list
        cout << "Original List: ";
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    
        // Reverse the list
        Solution s;
        ListNode* reversedHead = s.reverseList(head);
    
        // Print the reversed list
        cout << "Reversed List: ";
        temp = reversedHead;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    
        return 0;
}