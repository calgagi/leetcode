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

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int r = 0;
        return helper(root, r);
    }
    
    TreeNode* helper(TreeNode* root, int& x) {
        TreeNode* a = NULL, *b = NULL;
        int r = x+1, l = x+1;
        if (root->right) a = helper(root->right, r);
        if (root->left) b = helper(root->left, l);
        x = max(l, r);
        if (l == r) return root;
        return l < r ? a : b;
    }
};
