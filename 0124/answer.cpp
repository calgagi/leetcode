/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return -1e9;
        }
        int l = dfs(root->left), r = dfs(root->right);
        ans = max({ans, root->val, root->val + l, root->val + r, root->val + l + r, l, r});
        //cout << root->val << " " << l << " " << r << endl;
        return max(root->val + max(l, r), root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = max(ans, dfs(root));
        return ans;
    }
};
