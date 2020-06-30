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
    
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!helper(root, to_delete))
            res.push_back(root);
        return res;
    }
    
    bool helper(TreeNode* root, vector<int>& to_delete) {
        if (!root) return false;
        bool r = false, l = false;
        if (root->right) r = helper(root->right, to_delete);
        if (root->left) l = helper(root->left, to_delete);
        if (r) root->right = NULL;
        if (l) root->left = NULL;
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if (!r && root->right) res.push_back(root->right);
            if (!l && root->left) res.push_back(root->left);
            return true;
        } else return false;
    }    
};
