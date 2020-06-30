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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head, *slow = head, *prev;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        ListNode* l3 = merge(l1, l2);
        return l3;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (!l1 && l2) return l2;
        if (!l2 && l1) return l1;
        
        ListNode* r = NULL;
        if (l1->val < l2->val) {
            r = l1;
            l1 = l1->next;
        } else {
            r = l2;
            l2 = l2->next;
        }
        ListNode* res = r;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                r->next = l1;
                l1 = l1->next;
            } else {
                r->next = l2;
                l2 = l2->next;
            }
            r = r->next;
        }
        while (l1) {
            r->next = l1;
            l1 = l1->next;
            r = r->next;
        }
        while (l2) {
            r->next = l2;
            l2 = l2->next;
            r = r->next;
        }
        return res;
    }
};
