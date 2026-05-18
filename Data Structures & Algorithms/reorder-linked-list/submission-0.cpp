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

    ListNode* findMid(ListNode* &node){
        ListNode* slow = node;
        ListNode* fast = node->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* t1 = head;
        ListNode* t2 = reverse(mid->next);
        mid->next = NULL;

        ListNode* ansHead = new ListNode(-1);
        ListNode* tail = ansHead;

        while(t1 || t2){
            if(t1){
                tail->next = t1;
                tail = t1;
                t1 = t1->next;
            }
            if(t2){
                tail->next = t2;
                tail = t2;
                t2 = t2->next;
            }
        }

        head = ansHead->next;
    }
};
