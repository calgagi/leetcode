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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* r = new TreeNode(v);
            r->left = root;
            return r;
        }
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        vector<TreeNode*> nodes;
        while (!s.empty()) {
            int h = s.top().second;
            TreeNode* t = s.top().first;
            s.pop();
            if (h == d-1) {
                nodes.push_back(t);
                continue;
            }
            if (t->left)
                s.push({t->left, h+1});
            if (t->right)
                s.push({t->right, h+1});
        }
        for (int i = 0; i < nodes.size(); i++) {
            TreeNode* tempR = nodes[i]->right, *tempL = nodes[i]->left;
            nodes[i]->right = new TreeNode(v);
            nodes[i]->right->right = tempR;
            nodes[i]->left = new TreeNode(v);
            nodes[i]->left->left = tempL;
        }
        return root;
    }
};
