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
    int res = 0;
    
    // Sum, Valid, Min, Max
    tuple<int,bool,int,int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 1, 1e9, -1e9};
        }
        int s1, s2, v1, v2, mn1, mn2, mx1, mx2;
        tie(s1, v1, mn1, mx1) = dfs(root->left);
        tie(s2, v2, mn2, mx2) = dfs(root->right);
        if (mn2 > root->val && mx1 < root->val && v1 && v2) {
            res = max(res, root->val+s1+s2);
        } else {
            return {0, 0, 0, 0};
        }
        return {s1+s2+root->val, 1, min({mn1, mn2, root->val}), max({mx1, mx2, root->val})};
    }
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};
