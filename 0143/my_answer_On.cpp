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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        vector<ListNode*> n;
        ListNode* it = head;
        while (it) {
            n.push_back(it);
            it = it->next;
        }
        for (int i = 0, j = n.size()-1; i < j; i++, j--) {
            n[i]->next = n[j];
            n[j]->next = n[i+1];
        }
        n[n.size()/2]->next = NULL;
    }
};
