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
    // O(nlogn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<ListNode*> c = lists;
        for (int i = 0; i < n; i++) {
            if (!c[i]) continue;
            q.push({c[i]->val, i});
        }
        if (q.empty()) return NULL;
        ListNode* res = c[q.top().second];
        int i = q.top().second;
        q.pop();
        c[i] = c[i]->next;
        if (c[i]) q.push({c[i]->val, i});
        ListNode* it = res;
        while (!q.empty()) {
            it->next = c[q.top().second];
            it = it->next;
            i = q.top().second;
            q.pop();
            c[i] = c[i]->next;
            if (c[i]) q.push({c[i]->val, i});
        }
        return res;
    }
};
