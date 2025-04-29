#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* fast = head;
            ListNode* slow = head;

            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow) return true;
            }
            
            return false;
        }
    };


    int main() {
        // Create a linked list with a cycle
        ListNode* head = new ListNode(3);
        ListNode* second = new ListNode(2);
        ListNode* third = new ListNode(0);
        ListNode* fourth = new ListNode(-4);
    
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = second; // Creates a cycle (last node points to the second node)
    
        Solution s;
        if (s.hasCycle(head)) {
            cout << "The linked list has a cycle." << endl;
        } else {
            cout << "The linked list does not have a cycle." << endl;
        }
    
        // Note: In a real-world scenario, you should free the allocated memory.
        // However, since this list has a cycle, freeing memory would require breaking the cycle first.
    
        return 0;
    }