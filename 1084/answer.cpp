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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        long long t = helper(root, limit, 0);
        if (t < limit) return NULL;
        return root;
    }
    
    long long helper(TreeNode* root, int limit, int s) {
        if (!root->left && !root->right) {
            return s + root->val;
        }
        else {
            long long l = -INFINITY, r = -INFINITY;
            if (root->left) l = helper(root->left, limit, s + root->val);
            if (root->right) r = helper(root->right, limit, s + root->val);
            if (r < limit) root->right = NULL;
            if (l < limit) root->left = NULL;
            return max(r, l);
        }
    }
};
