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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* r = NULL, *l = NULL;
        int t = pre[0]; pre.erase(pre.begin());
        if (t == post[0]) {
            post.erase(post.begin());
            return new TreeNode(t);
        }
        if (t != post[0])
            l = constructFromPrePost(pre, post);
        if (t != post[0])
            r = constructFromPrePost(pre, post);
        TreeNode* root = new TreeNode(t);
        post.erase(post.begin());
        root->left = l;
        root->right = r;
        return root;
    }
};
