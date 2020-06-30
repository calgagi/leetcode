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
    unordered_map<TreeNode*, long long> dp;
    long long res = 0;
    
    long long get_sum(TreeNode* root) {
        if (dp.count(root))
            return dp[root];
        dp[root] = root->val + get_sum(root->left) + get_sum(root->right);
        return dp[root];
    }
    
    void dfs(TreeNode* root, long long cur) {
        if (root == NULL) return;
        cur += root->val;
        long long left = dp[root->left];
        long long right = dp[root->right];
        res = max({left * (right + cur), right * (left + cur), res});
        if (left + right < cur) return;
        dfs(root->right, left + cur);
        dfs(root->left, right + cur);
        return;
    }
    
    int maxProduct(TreeNode* root) {
        dp[NULL] = 0;
        get_sum(root);
        dfs(root, 0);
        return res % MOD;
    }
};
