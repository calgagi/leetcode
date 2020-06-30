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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<ListNode*, int>> s;
        vector<int> r;
        int i = 0;
        while (head) {
            while (!s.empty() && s.top().first->val < head->val) {
                r[s.top().second] = head->val;
                s.pop();
            }
            r.push_back(0);
            s.push({head, i});
            head = head->next;
            i++;
        }
        return r;
    }
};
