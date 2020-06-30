/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* it = head->next, * new_head = head->next; 
        ListNode* prev = head, *old = NULL;
        while (it) {
            ListNode* temp = it->next;
            it->next = prev;
            prev->next = temp;
            if (old) old->next = it;
            old = prev;
            prev = prev->next;
            if (!prev) break;
            it = prev->next;
        }
        return new_head;
    }
};
