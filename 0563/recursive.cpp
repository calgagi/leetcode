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
    int total;
    
    int findTilt(TreeNode* root) {
        this->total = 0;
        helper(root);
        return this->total;
    }
    
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int r = helper(root->right);
        int l = helper(root->left);
        total += abs(r - l);
        return r + l + root->val;
    }
};
