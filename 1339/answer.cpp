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
    const long long MOD = 1e9 + 7;
    // Need to keep track of current sum
    // Get sum of both trees
    // Check if big
    long long res = 0;
    
    long long get_sum(TreeNode* root) {
        if (root == NULL)
            return 0;
        return (long long) root->val + get_sum(root->left) + get_sum(root->right);
    }
    
    long long dfs(TreeNode* root, const long long& tot) {
        if (root == NULL) return 0;
        if (root->right == root->left) return root->val;
        long long l = dfs(root->left, tot), r = dfs(root->right, tot);
        res = max({(tot-r) * r, (tot-l) * l, res});
        return l+r+root->val;
    }
    
    int maxProduct(TreeNode* root) {  
        long long tot = get_sum(root);
        dfs(root, tot);
        return res % MOD;
    }
};
