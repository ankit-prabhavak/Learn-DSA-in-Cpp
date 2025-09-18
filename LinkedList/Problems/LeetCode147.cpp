#include <iostream>

using namespace std;


/**
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
    ListNode* insertionSortList(ListNode* head) {

        if(head == NULL) return nullptr;

        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* prev = dummy;

            while(prev->next != NULL && prev->next->val < curr->val) {
                prev = prev->next;
            }

            ListNode* temp = curr->next;

            curr->next = prev->next;
            prev->next = curr;


            curr = temp;
        }



        return dummy->next;

    }
};