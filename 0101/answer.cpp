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
    bool helper(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL || r2 == NULL) {
            return r1 == r2;
        } 
        if (r1->val != r2->val) {
            return 0;
        }
        return helper(r1->right, r2->left) && helper(r1->left, r2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return 1;
        }
        return helper(root->left, root->right);
    }
};
