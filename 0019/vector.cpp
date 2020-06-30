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
        vector<ListNode*> v;
        ListNode* it = head;
        while (it) {
            v.push_back(it);
            it = it->next;
        }
        int p = v.size()-n-1;
        if (p < 0) head = p+2 < v.size() ? v[p+2] : NULL;
        else v[p]->next = p+2 < v.size() ? v[p+2] : NULL;
        return head;
    }
};
