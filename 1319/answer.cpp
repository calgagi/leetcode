class Solution {
public:
    vector<bool> marked;
    vector<vector<int>> g;

    void dfs(int i) {
        marked[i] = 1;
        for (auto& e : g[i]) {
            if (!marked[e]) dfs(e);
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        marked.assign(n, false);
        g.assign(n, vector<int>());
        if ((int) connections.size() < n-1) return -1;
        for (auto& c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        // find connected components
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                cc++;
                dfs(i);
            }
        }
        return cc-1;
    }
};
