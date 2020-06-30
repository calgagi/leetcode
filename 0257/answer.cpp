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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        stack<pair<string, TreeNode*>> s;
        s.push({"", root});
        while (!s.empty()) {
            string p = s.top().first;
            TreeNode* c = s.top().second;
            s.pop();
            p += to_string(c->val);
            if (c->left)
                s.push({p + "->", c->left});
            if (c->right)
                s.push({p + "->", c->right});
            if (!c->right && !c->left)
                res.push_back(p);
        }
        return res;
    }
};
