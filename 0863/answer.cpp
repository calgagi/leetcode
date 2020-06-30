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
    map<TreeNode*, vector<TreeNode*>> graph;
    unordered_set<TreeNode*> visited;
    
    void dfs1(TreeNode* cur) {
        if (cur == NULL) {
            return;
        }
        if (cur->right) {
            graph[cur].push_back(cur->right);
            graph[cur->right].push_back(cur);
        }
        if (cur->left) {
            graph[cur].push_back(cur->left);
            graph[cur->left].push_back(cur);
        }
        dfs1(cur->left);
        dfs1(cur->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs1(root);
        queue<pair<TreeNode*, int>> q;
        q.emplace(target, K);
        vector<int> res;
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int s = q.front().second;
            q.pop();
            if (visited.count(cur)) {
                continue;
            }
            visited.insert(cur);
            if (s == 0) {
                res.push_back(cur->val);
            } else {
                for (auto& e : graph[cur]) {
                    q.emplace(e, s-1);
                }
            }
        }
        return res;
    }
};
