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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> s;
        int c = 0;
        TreeNode *r = root;
        s.push(root);
        while (!s.empty() || root) {
            while (root && root->right) {
                root = root->right;
                s.push(root);
            }
            root = s.top(); s.pop();
            if (root) {
                c += root->val;
                root->val = c;
                if (root->left) {
                    s.push(root->left);
                }
            }
            root = root->left;

        }
        return r;
    }
};
