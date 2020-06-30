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
    unordered_map<int, int> c; 

    int recurse(TreeNode* root) {
        int l = 0, r = 0;
        if (root->left) l = recurse(root->left);
        if (root->right) r = recurse(root->right);
        this->c[l+r+root->val]++;
        return l+r+root->val;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return vector<int>(0);
        recurse(root);
        vector<int> r;
        int m = -INFINITY;
        for (auto it = c.begin(); it != c.end(); it++) 
            m = max(m, it->second);
        for (auto it = c.begin(); it != c.end(); it++)
            if (it->second == m) r.push_back(it->first);
        return r;
    }
};
