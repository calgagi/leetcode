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
    int findBottomLeftValue(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        int r = root->val, d = 0;
        while (!s.empty()) {
            TreeNode* n = s.top().first;
            int depth = s.top().second;
            s.pop();
            if (d < depth) {
                d = depth;
                r = n->val;
            }
            if (n->right) s.push({n->right, depth+1});
            if (n->left) s.push({n->left, depth+1});
        }
        return r;
    }
};
