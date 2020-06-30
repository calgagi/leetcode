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
        vector<vector<TreeNode*>> levels;
        int streak = 0;
        stack<int> s;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '-')
                streak++;
            else {
                while (!s.empty() && s.top() > streak) {
                    levels[s.top()].push_back(NULL);
                    s.pop();
                }
                string n;
                while (i < S.length() && S[i] != '-') {
                    n += S[i];
                    i++;
                }
                i--;
                TreeNode* t = new TreeNode(stoi(n));
                if (levels.size() < streak+1) 
                    levels.push_back(vector<TreeNode*>());
                levels[streak].push_back(t);
                if (!s.empty() && s.top() == streak) s.pop();
                else s.push(streak);
                streak = 0;
            }
        }
        
        TreeNode* r = levels[0][0];
        for (int j = 0; j < levels.size()-1; j++) {
            for (int i = 0; i < levels[j].size(); i++) {
                if (!levels[j][i]) {
                    levels[j].erase(levels[j].begin()+i);
                    i--;
                    continue;
                }
                if (i*2 < levels[j+1].size())
                    levels[j][i]->left = levels[j+1][i*2];
                if ((i*2)+1 < levels[j+1].size())
                    levels[j][i]->right = levels[j+1][(i*2)+1];
            }
        }
        return r;
    }
};
