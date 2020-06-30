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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    int length;
    
    Solution(ListNode* head) {
        srand(time(NULL));
        this->head = head;
        this->length = 0;
        ListNode* it = head;
        while (it) {
            it = it->next;
            this->length++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r = rand()%length;
        int i = 0;
        ListNode* it = this->head;
        while (i < r) {
            it = it->next;
            i++;
        }
        return it->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
