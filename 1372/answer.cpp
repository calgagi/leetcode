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
    int res = 0;
    
    // StartL, StartR
    pair<int,int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0,0};
        }
        
        pair<int,int> a = dfs(root->left), b = dfs(root->right);
        res = max(1+a.second, res);
        res = max(1+b.first, res);
        return {1+a.second, 1+b.first};
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return res-1;
    }
};
