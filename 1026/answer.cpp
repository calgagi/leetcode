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
    unordered_map<TreeNode*, int> MIN, MAX;
    int res = 0;
    
    bool dfs(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int a = cur->val;
        MAX[cur] = MIN[cur] = a;
        for (auto e : {cur->left, cur->right}) {
            if (dfs(e)) {
                res = max({res, abs(a - MIN[e]), abs(a - MAX[e])});
                MAX[cur] = max(MAX[cur], MAX[e]);
                MIN[cur] = min(MIN[cur], MIN[e]);
            }
        }
        return 1;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return res;
    }
};
