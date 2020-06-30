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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        unordered_map<int,int> seen;
        ListNode* it = new_head;
        while (it->next) {
            if (seen.find(it->next->val) != seen.end()) {
                seen[it->next->val]++;
                ListNode* t = it->next;
                it->next = it->next->next;
                delete t;
            } else {
                seen[it->next->val] = 1;
                it = it->next;
            }
        }
        it = new_head;
        while (it->next) {
            if (seen[it->next->val] != 1) {
                ListNode* t = it->next;
                it->next = it->next->next;
                delete t;
            } else {
                it = it->next;
            }
        }
        return new_head->next;
    }
};
