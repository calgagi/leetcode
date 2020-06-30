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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* head2 = new ListNode(5);
        head2->next = head;
        ListNode* it = head, * prev = head2;
        for (int i = 1; i < m; i++) {
            prev = it;
            it = it->next;
        }
        ListNode* new_last = it;
        for (int i = m; i <= n; i++) {
            ListNode* temp2 = prev->next;
            prev->next = it;
            ListNode* temp = it->next;
            it->next = temp2;
            it = temp;
        }
        new_last->next = it;
        return head2->next; 
    }
};
