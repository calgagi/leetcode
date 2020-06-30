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
    pair<int,int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        pair<int,int> l = dfs(root->left), r = dfs(root->right);
        return {max({l.second+r.second+1, l.first, r.first}), max(l.second,r.second)+1};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = dfs(root);
        return max({ans.first, ans.second, 1})-1;
    }
};
