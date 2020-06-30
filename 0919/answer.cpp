/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int v) {
        TreeNode* l;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            l = q.front(); q.pop();
            if (!l->left) break;
            else q.push(l->left);
            if (!l->right) break;
            else q.push(l->right);
        }
        if (!l->left) l->left = new TreeNode(v);
        else if (!l->right) l->right = new TreeNode(v);
        return l->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
