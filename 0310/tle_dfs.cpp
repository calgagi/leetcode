class Solution {
public:
    vector<vector<int>> g;

    int dfs(int current, int parent) {
        int r = 0;
        for (int i = 0; i < g[current].size(); i++) {
            if (g[current][i] == parent) continue;
            r = max(r, dfs(g[current][i], current));
        }
        return r+1;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        this->g = vector<vector<int>>(n);
        for (int i = 0; i < edges.size(); i++) {
            this->g[edges[i][0]].push_back(edges[i][1]);
            this->g[edges[i][1]].push_back(edges[i][0]);
        }
        
        int c = 0;
        vector<int> r;
        int mm = INT_MAX;
        for (int i = 0; i < n; i++) {
            int m = dfs(i, i);
            if (r.size() == 0 || m < mm) {
                r.clear();
                r.push_back(i);
                mm = m;
            } else if (m == mm) r.push_back(i);
        }
        return r;
    }
};
