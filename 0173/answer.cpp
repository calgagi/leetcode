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
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* x = s.top();
        s.pop();
        if (x->right) {
            TreeNode* it = x->right;
            while (it) {
                s.push(it);
                it = it->left;
            }
        }
        return x->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
