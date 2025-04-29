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
        ListNode *detectCycle(ListNode *head) {
            ListNode* fast = head;
            ListNode* slow = head;
            bool isCycle = false;

            while(fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow) {
                    isCycle = true;
                    break;
                }
            }

            if(!isCycle) {
                return NULL;
            }

            slow =head;
            while(slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }

            return slow;
            
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
        ListNode* cycleNode = s.detectCycle(head);
    
        if (cycleNode) {
            cout << "The cycle starts at node with value: " << cycleNode->val << endl;
        } else {
            cout << "There is no cycle in the linked list." << endl;
        }
    
        // Note: In a real-world scenario, you should free the allocated memory.
        // However, since this list has a cycle, freeing memory would require breaking the cycle first.
    
        return 0;
    }


