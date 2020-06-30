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
        if (!root) return r; 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            if (x) {
                r += to_string(x->val) + " ";
                q.push(x->left);
                q.push(x->right);
            } else
                r += "null ";
        }
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        queue<TreeNode*> q;
        string current = "";
        for (char &c : data) {
            if (c != ' ') {
                current += c;
            } else if (current != "null") {
                q.push(new TreeNode(stoi(current)));
                current = "";
            } else {
                q.push(NULL);
                current = "";
            }
        }
        queue<TreeNode*> s;
        TreeNode* r = q.front();
        s.push(r); q.pop();
        while (!q.empty()) {
            TreeNode* t = s.front();
            s.pop();
            if (!t) continue;
            t->left = q.front();
            q.pop();
            t->right = q.front();
            q.pop();
            s.push(t->left);
            s.push(t->right);
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
