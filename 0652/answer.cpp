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
    string dupe(TreeNode* root, unordered_map<string,int>& s, vector<TreeNode*>& res) {
        if (!root) return "#";
        string cur = to_string(root->val) + "," + dupe(root->left, s, res) + "," + dupe(root->right, s, res);
        if (s.find(cur) != s.end() && s[cur] == 1) res.push_back(root);
        s[cur]++;
        return cur;
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> s;
        vector<TreeNode*> res;
        dupe(root, s, res);
        return res;
    }
};
