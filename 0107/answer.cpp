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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> r;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        while (!s.empty()) {
            int l = s.top().second;
            TreeNode* t = s.top().first;
            s.pop();
            if (!t) continue;
            if (l > r.size()) r.push_back(vector<int>());
            r[l-1].push_back(t->val);
            s.push({t->right, l+1});
            s.push({t->left, l+1});
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
