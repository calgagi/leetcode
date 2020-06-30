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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*,int>> s;
        s.push({root, 0});
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            int state = s.top().second;
            s.pop();
            if (cur == NULL) continue;
            if (state < 2) s.push({cur, state+1});
            if (state == 0) s.push({cur->left, 0});
            else if (state == 1) s.push({cur->right, 0});
            else if (state == 2) res.push_back(cur->val);
        }
        return res;
    }
};
