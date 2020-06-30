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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        while (!s.empty()) {
            int c = s.top().second;
            TreeNode* t = s.top().first;
            s.pop();
            c += t->val;
            if (!t->left && !t->right && c == sum) return true;
            if (t->left) s.push({t->left, c});
            if (t->right) s.push({t->right, c});
        }
        return false;
    }
};
