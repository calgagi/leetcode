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
    TreeNode* r;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->r = NULL;
        this->helper(root, p, q);
        return this->r;
    }
    
    vector<bool> helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return {false, false};
        vector<bool> l = helper(root->left, p, q);
        vector<bool> r = helper(root->right, p, q);
        vector<bool> a = {l[0] || r[0] || p == root, l[1] || r[1] || q == root};
        if (a[0] && a[1] && !this->r) this->r = root;
        return a;
    }
};
