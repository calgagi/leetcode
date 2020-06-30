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
    map<TreeNode*, int> sz;
    int ans = -1;
    
    int dfs1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs1(root->left), right = dfs1(root->right);
        sz[root] = left + right + 1;
        return sz[root];
    }
    
    void dfs2(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        int left = sz[root->left];
        if (k == 1+left) {
            ans = root->val;
        } else if (k <= left) {
            dfs2(root->left, k);
        } else if (k > left+1) {
            dfs2(root->right, k - (left + 1));
        }
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        sz[NULL] = 0;
        int s = dfs1(root);
        dfs2(root, k);
        return ans;
    }
};
