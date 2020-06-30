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
    unordered_map<int,int> in;
    
    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int prs, int ins, int ine) {
        if (ins > ine || prs >= preorder.size()) {
            return NULL;
        }
        TreeNode* res = new TreeNode(preorder[prs]);
        int ini = in[preorder[prs]];
        res->left = help(preorder, inorder, prs+1, ins, ini-1);
        res->right = help(preorder, inorder, prs+ini-ins+1, ini+1, ine);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return help(preorder, inorder, 0, 0, inorder.size()-1);
    }
};
