#include <iostream>
#include <vector>
using namespace std;
/**
Definition for singly-linked list.
**/


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// Initial Solution, will not pass large test cases due to integer overflow
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        string num1 = "";
        string num2 = "";

        while(l1 != nullptr){
            num1 = to_string(l1->val) + num1;
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            num2 = to_string(l2->val) + num2;
            l2 = l2->next;
        }
        
        string sum = to_string(stoi(num1) + stoi(num2));

        ListNode* head = new ListNode(sum[sum.size() - 1] - '0');
        ListNode* temp = head;
        for(int i = sum.size() - 2; i >= 0; i--){
            temp->next = new ListNode(sum[i] - '0');
            temp = temp->next;
        }

        return head;
        
    }
};

// Optimized Solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};