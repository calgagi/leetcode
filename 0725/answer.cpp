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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // Find length
        int length = 0;
        ListNode* it = root;
        while (it) {
            length++;
            it = it->next;
        }
        int min_size = length / k;
        int num_extra = length % k;
        it = root;
        int i = 0;
        vector<ListNode*> r;
        while (it || i < k) {
            int j = 0;
            r.push_back(it);
            ListNode* prev = NULL;
            while (it && j < min_size) {
                prev = it;
                it = it->next;
                j++;
            }
            if (it && num_extra) {
                prev = it;
                it = it->next;
                num_extra--;
            }
            if (prev)
                prev->next = NULL;
            i++;
        }
        return r;
    }
};
