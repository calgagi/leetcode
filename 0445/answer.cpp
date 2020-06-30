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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        stack<int> f;
        while (!s1.empty() || !s2.empty()) {
            int n1 = 0, n2 = 0;
            if (!s1.empty()) {
                n1 = s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                n2 = s2.top()->val;
                s2.pop();
            }
            f.push((carry + n1 + n2) % 10);
            carry = (n1 + n2 + carry) / 10;
        }
        ListNode* r = new ListNode(carry);
        ListNode* i = r;
        while (!f.empty()) {
            i->next = new ListNode(f.top());
            f.pop();
            i = i->next;
        }
        if (carry) return r;
        else return r->next;
    }
};
