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
    TreeNode* bstFromPreorder(vector<int>& preorder, long MN = 1e10) {
        if (preorder.empty()) {
            return NULL;
        }
        TreeNode* ans = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        if (!preorder.empty() && preorder[0] < ans->val) {
            ans->left = bstFromPreorder(preorder, ans->val);
        }
        if (!preorder.empty() && preorder[0] > ans->val && (long) preorder[0] < MN) {
            ans->right = bstFromPreorder(preorder, MN);
        }
        return ans;
    }
};
