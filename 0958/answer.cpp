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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0, count = 0;
        while (!q.empty()) {
            TreeNode* t = q.front().first;
            int l = q.front().second;
            q.pop();
            if (t) {
                if (level == l) 
                    count++;
                else return false;
                if (count == pow(2, level)) {
                    level++;
                    count = 0;
                }
                q.push({t->left, l+1});
                q.push({t->right, l+1});
            } else {
                while (!q.empty()) {
                    if (q.front().first) return false;
                    q.pop();
                }
            }
        }
        return true;
    }
};
