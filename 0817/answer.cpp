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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int r = 0; 
        while (head) {
            if (s.count(head->val) && (!head->next || s.find(head->next->val) == s.end()))
                r++;
            head = head->next;
        }
        return r;
    }
};
