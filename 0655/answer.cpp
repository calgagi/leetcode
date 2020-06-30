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
    
    void helper(vector<vector<string>>& r, int h, int s, int p, TreeNode* x) {
        r[h][p] = to_string(x->val);
        s /= 2;
        if (x->right) {
            helper(r, h+1, s, p+s, x->right);
        }
        if (x->left) {
            helper(r, h+1, s, p-s, x->left);   
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int h = 0;
        while (!q.empty()) {
            TreeNode* t = q.front().first;
            int l = q.front().second;
            q.pop();
            if (!t) continue;
            h = max(l, h);
            q.push({t->left, l+1});
            q.push({t->right, l+1});
        }
        int s = pow(2, h+1)-1;
        vector<vector<string>> r(h+1, vector<string>(s, ""));
        helper(r, 0, pow(2, h), pow(2, h)-1, root);
        return r;
    }
};
