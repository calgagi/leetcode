class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode* it = head, *slow = head;
        int l = 0;
        while (it) {
            it = it->next;
            l++;
        }
        k %= l;
        it = head;
        for (int i = 0; it && i < k; i++) {
            it = it->next;
        }
        while (it->next) {
            it = it->next;
            slow = slow->next;
        }
        it->next = head;
        ListNode* r = slow->next;
        slow->next = NULL;
        return r;
    }
};
