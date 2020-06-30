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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* it = head;
        stack<int> s;
        while (it) {
            s.push(it->val);
            it = it->next;
        }
        int i = 0;
        while (!s.empty()) {
            res += pow(2, i) * s.top();
            s.pop();
            i++;
        }
        return res;
    }
};
