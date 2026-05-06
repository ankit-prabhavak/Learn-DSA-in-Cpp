// LeetCode 61. Rotate List

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        int count = 0;

        while(temp){
             count++;
             temp = temp->next;
        }

        k = k % count;
        temp = head;

        while(k){
            ListNode* jump = temp;
            while(temp){

                if(temp->next->next == nullptr){
                    ListNode* block = new ListNode(temp->next->val);
                    temp->next = nullptr;
                    block->next = jump;
                    temp = block;
                    break;
                }

                temp = temp->next;

            }
            
            k--;
            
        }

        return temp;

    }
};