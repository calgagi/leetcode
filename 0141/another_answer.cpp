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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL && slow != fast) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return fast == slow; 
    }
};
