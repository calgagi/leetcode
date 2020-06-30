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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root1);
        while (!q.empty()) {
            TreeNode* t = q.front(); q.pop();
            if (t == NULL) continue;
            res.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
        }
        q.push(root2);
        while (!q.empty()) {
            TreeNode* t = q.front(); q.pop();
            if (t == NULL) continue;
            res.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
