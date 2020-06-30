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
   
    void insert_next(ListNode* head, ListNode* to_insert) {
        ListNode* t = head->next;
        head->next = to_insert;
        to_insert->next = t;
        return;
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* fast = head->next, * slow = head;
        while (fast && fast->next) {
            // Get first three nodes (fast -> t -> x)
            ListNode* t = fast->next;
            ListNode* x = t->next;
            // Insert t at slow's location, fast still points to t
            insert_next(slow, t);
            // Slow goes to t
            slow = slow->next;
            // Remove t from after fast (fast -> x)
            fast->next = x;
            // Update fast to go to x
            fast = fast->next;
        }
        return head;
    }
};
