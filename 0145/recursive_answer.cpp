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
    vector<int> res;
    
    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        res.push_back(root->val);
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }
};
