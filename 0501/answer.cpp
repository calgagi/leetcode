/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return vector<int>();
        unordered_map< int, int > freq;
        queue< TreeNode* > q;
        int m = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            freq[t->val]++;
            m = max(m, freq[t->val]);
            if (t->right) q.push(t->right);
            if (t->left) q.push(t->left);
        }
        vector<int> res;
        for (auto it = freq.begin(); it != freq.end(); it++)
            if (m == it->second) res.push_back(it->first);
        return res;
    }
};
