/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string r = "";
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* x = s.top();
            s.pop();
            if (x == NULL) {
                r += "null ";
            } else {
                r += to_string(x->val) + " ";
                s.push(x->right);
                s.push(x->left);
            }
        }
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        queue<TreeNode*> q;
        string t = "";
        while (i < data.length()) {
            if (data[i] == ' ' && t != "") {
                if (t == "null") {
                    q.push(NULL);
                } else {
                    q.push(new TreeNode(stoi(t)));
                }
                t = "";
            } else {
                t += data[i];
            }
            i++;
        }
        TreeNode* r = NULL;
        if (!q.empty()) {
            r = q.front();
            q.pop();
            helper(r, q);
        }
        return r;
    }
    
    void helper(TreeNode* r, queue<TreeNode*> &q) {
        if (q.empty()) return;
        r->left = q.front();
        q.pop();
        if (r->left)
            helper(r->left, q);
        r->right = q.front();
        q.pop();
        if (r->right)
            helper(r->right, q);
        return;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
