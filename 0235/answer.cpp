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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        if (r && l) return root;
        if (root == p || root == q) return root;
        if (r || l) return r ? r : l;
        return NULL;
    }
};
