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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if (!root) return r;
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        while (!s.empty()) {
            TreeNode* t = s.top().first;
            int h = s.top().second;
            s.pop();
            if (r.size() < h) r.push_back(t->val);
            if (t->left) s.push({t->left, h+1});
            if (t->right) s.push({t->right, h+1});
        }
        return r;
    }
};
