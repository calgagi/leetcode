class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;
    
    bool dfs(int cur, int c) {
        if (color[cur] != -1) {
            return color[cur] == c;
        }
        color[cur] = c;
        bool res = true;
        for (auto& e : g[cur]) {
            res &= dfs(e, (c == 1 ? 0 : 1));
        }
        return res;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        g.resize(N);
        color.assign(N, -1);
        for (auto& e : dislikes) {
            e[0]--, e[1]--;
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        bool res = true;
        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                res &= dfs(i, 1);
            }
        }
        return res;
    }
};
