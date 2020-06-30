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
    TreeNode* recoverFromPreorder(string S) {
        if (S == "") return NULL;
        stack<pair<TreeNode*,int>> s;
        int i = 0; string n;
        while (i < S.length() && S[i] != '-') {
            n += S[i];
            i++;
        }
        TreeNode* r = new TreeNode(stoi(n));
        n = "";
        s.push({r, 0});
        while (!s.empty() && i < S.length()) {
            int streak = 0;
            for ( ; i < S.length() && S[i] == '-'; i++) streak++;
            while (!s.empty() && s.top().second+1 != streak) s.pop();
            int l = s.top().second;
            TreeNode* t = s.top().first;
            s.pop();
            for ( ; i < S.length() && S[i] != '-'; i++) n += S[i];
            if (!t->left) {
                t->left = new TreeNode(stoi(n));
                s.push({t, l});
                s.push({t->left, l+1});
            } else if (!t->right) {
                t->right = new TreeNode(stoi(n));
                s.push({t->right, l+1});
            }
            n = "";
        }
        return r;
    }
};
