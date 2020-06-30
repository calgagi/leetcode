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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        int i;
        for (i = 0; i < n+1 && fast; i++) 
            fast = fast->next;
        if (!fast && i < n+1) return head->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow->next)
            slow->next = slow->next->next;
        return head;
    }
};
