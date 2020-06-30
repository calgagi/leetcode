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
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        int ret = 0;
        q.push({root, 0});
        // 1 == parent is even, 2 == grandparent is even, 3 == grandparent && parent, 0 = nothing
        while (!q.empty()) {
            TreeNode* t = q.front().first;
            int l = q.front().second;
            q.pop();
            if (t == NULL) continue;
            if (l == 2 || l == 3) {
                ret += t->val;
            }
            if (l == 1) l = 2;
            else if (l == 2) l = 0;
            else if (l == 3) l = 2;
            if (!(t->val&1)) {
                if (l == 0) l = 1;
                else if (l == 1) l = 3;
                else if (l == 2) l = 3;
            }
            q.push({t->left, l});
            q.push({t->right, l});
        }
        return ret;
    }
};
