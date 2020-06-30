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
    vector<int> largestValues(TreeNode* root) {
        vector<int> r;
        if (!root) return r;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            pair<TreeNode*, int> x = q.front();
            q.pop();
            if (x.second > r.size())
                r.push_back(-INFINITY);
            r[x.second-1] = max(r[x.second-1], (x.first)->val);
            if ((x.first)->right) q.push({(x.first)->right, x.second+1});
            if ((x.first)->left) q.push({(x.first)->left, x.second+1});
        }
        return r;
    }
};
