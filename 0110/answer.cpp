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
    bool res = 1;
    
    int dfs(TreeNode* r) {
        if (r == NULL) {
            return 0;
        }
        int a = dfs(r->left),b =  dfs(r->right);
        if (abs(a-b) > 1) {
            res = 0;
        }
        return max(a,b)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
};
