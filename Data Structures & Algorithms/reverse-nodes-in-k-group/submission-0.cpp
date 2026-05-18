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

    int getLength(ListNode* &head){
        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* solve(ListNode* &head, int k, int n){

        if(n < k) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        int x = k;

        while(curr && x > 0){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            x--;
        }

        head->next = solve(curr, k, n-k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLength(head);
        return solve(head, k, n);
    }
};
