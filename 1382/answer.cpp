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
    vector<pair<int,TreeNode*>> s;
    
    void dfs1(TreeNode* root) {
        if (!root) {
            return;
        }
        s.push_back({root->val, root});
        dfs1(root->left);
        dfs1(root->right);
    }
    
    TreeNode* build_tree(int l, int r) {
        if (l > r) {
            return NULL;
        }
        int m = l + (r-l)/2;
        TreeNode* res = s[m].second;
        res->left = build_tree(l, m-1);
        res->right = build_tree(m+1, r);
        return res;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs1(root);
        sort(s.begin(), s.end());
        return build_tree(0, s.size()-1);
    }
};
