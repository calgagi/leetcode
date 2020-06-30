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
    int sumRootToLeaf(TreeNode* root) {
        int r = 0;
        stack<pair<TreeNode*, string>> s;
        s.push(make_pair(root, ""));
        while (!s.empty()) {
            pair<TreeNode*, string> i = s.top();
            s.pop();
            i.second += to_string(i.first->val);
            if (!i.first->right and !i.first->left) {
                r += stoi(i.second, nullptr, 2);
            }
            if (i.first->right) {
                s.push(make_pair(i.first->right, i.second));
            }
            if (i.first->left) {
                s.push(make_pair(i.first->left, i.second));
            }
        }
        return r;
    }
    
    
};
