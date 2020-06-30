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
    unordered_map<int, unordered_map<int, int>> m;
    vector<TreeNode*> r;
    
    bool helper(TreeNode* root) {
        bool dupR = true, dupL = false;
        if (!root->right || helper(root->right)) dupR = true;
        if (!root->left || helper(root->left)) dupL = true;
        
        
        if (dupR && root->right) {
            if (m[root->val].find(root->right->val) != m[root->val].end() && m[root->val][root->right->val]) dupR = true;
            else dupR = false;
        }
        if (dupL && root->left) {
            if (m[root->val].find(root->left->val) != m[root->val].end() && m[root->val][root->left->val] == 1) dupR = true;
            else dupL = false;
        }
         
        if (root->left) m[root->val][root->left->val]++;
        if (root->right) m[root->val][root->right->val]++;
        if (dupR && dupL) r.push_back(root);
        return dupR && dupL;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root); 
       
        return this->r;
    }
};
