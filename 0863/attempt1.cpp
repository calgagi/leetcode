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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<vector<TreeNode*>> tree;
        stack<pair<TreeNode*, int>> s;
        int ti, tj;
        s.push({root, 0});
        while (!s.empty()) {
            TreeNode* x = s.top().first;
            int level = s.top().second;
            s.pop();
            if (level <= tree.size()) tree.push_back(vector<TreeNode*>());
            tree[level].push_back(x);
            if (!x) continue;
            if (x == target) {
                ti = level;
                tj = tree[level].size()-1;
            }
            s.push({x->right, level+1});
            s.push({x->left, level+1});
        }
        vector<int> r;
        int div = pow(2, ti-1);
        int begin = tj < div ? 0 : 1;
        int end = tj < div ? 1 : 2;
        for (int i = begin*pow(2, ti+K-1); i < end*pow(2, ti+K-1); i++)
            if (ti+K < tree.size() && tree[ti+K][i]) r.push_back(tree[ti+K][i]->val);
        if (ti-K < 0) { 
            begin = !begin;
            end = end == 1 ? 2 : 1;
        }
        for (int i = begin*pow(2, abs(ti-K)-1); i < end*pow(2, abs(ti-K)-1); i++)
            if (abs(ti-K) < tree.size() && tree[abs(ti-K)][i]) r.push_back(tree[abs(ti-K)][i]->val);
        return r;
        
        
    }
};
