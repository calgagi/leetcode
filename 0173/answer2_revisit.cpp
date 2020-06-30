/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        return;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* r = s.top();
        int res = r->val;
        s.pop();
        r = r->right;
        while (r) {
            s.push(r);
            r = r->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
