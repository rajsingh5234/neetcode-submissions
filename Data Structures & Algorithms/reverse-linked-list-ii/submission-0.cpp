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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int pos = 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(pos != left){
            prev = curr;
            curr = curr->next;
            pos++;
        }

        ListNode* f = prev;
        ListNode* s = curr;

        while(pos<=right){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            pos++;
        }

        s->next = curr;
        if(!f) return prev;
        f->next = prev;

        return head;
    }
};