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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        int sum = 0, carry = 0;

        while(t1 || t2 || carry != 0){
            int v1 = 0, v2 = 0;

            if(t1) v1 = t1->val;
            if(t2) v2 = t2->val;

            sum = v1 + v2 + carry;

            int digit = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }

        return head->next;
    }
};
