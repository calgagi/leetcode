/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string cur = "";
    int ans = 0;
    
    bool is_palindromic(const string& s) {
        vector<bool> cnt(10, 0);
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i]-'0'] = !cnt[s[i]-'0'];   
        }
        int odd = 0;
        for (int i = 0; i < 10; i++) {
            odd += cnt[i];
        }
        return odd <= 1;
    }
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        cur += root->val+'0';
        if (!root->left && !root->right) {
            if (is_palindromic(cur)) {
                ans++;
            }
        }
        dfs(root->left);
        dfs(root->right);
        cur.pop_back();
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};
