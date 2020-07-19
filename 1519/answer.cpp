class Solution {
public:
    vector<vector<int>> cnts, graph;
    vector<int> ans;
    string labels;
    
    void dfs(int i, int par) {
        if (ans[i] != -1) {
            return;
        }
        ans[i] = 0;
        for (int& to : graph[i]) {
            if (to == par) {
                continue;
            }
            dfs(to, i);
            for (int j = 0; j < 26; j++) {
                cnts[i][j] += cnts[to][j];
            }
        }
        cnts[i][labels[i] - 'a']++;
        ans[i] = cnts[i][labels[i] - 'a'];
        return;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        cnts.assign(n, vector<int>(26));
        graph.resize(n);
        this->labels = labels;
        for (int i = 0; i < (int) edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        ans.assign(n, -1);
        dfs(0, -1);
        
        return ans;
    }
};
