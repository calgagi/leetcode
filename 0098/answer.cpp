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
    map<TreeNode*, long> MIN, MAX;
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        MIN[root] = MAX[root] = root->val;
        dfs(root->left);
        dfs(root->right);
        MIN[root] = min({MIN[root], MIN[root->right], MIN[root->left]});
        MAX[root] = max({MAX[root], MAX[root->right], MAX[root->left]});
        return;
    }
    
    bool helper(TreeNode* root) {
        if (!root) {
            return 1;
        }
        long a = root->val;
        bool x = helper(root->right) && helper(root->left);
        return MAX[root->left] < a && MIN[root->right] > a && x;
    }
    
    bool isValidBST(TreeNode* root) {
        MIN[NULL] = LONG_MAX;
        MAX[NULL] = LONG_MIN;
        dfs(root);
        return helper(root);
    }
};
