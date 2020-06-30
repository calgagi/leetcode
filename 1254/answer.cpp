class Solution {
public:
    vector<vector<int>> g;
    int m, n;
    
    bool dfs(int i, int j) {
        if (i >= m || j >= n || j < 0 || i < 0) {
            return 0;
        }
        if (g[i][j] == 2 || g[i][j] == 1) {
            return 1;
        }
        g[i][j] = 2;
        bool u = dfs(i+1, j);
        bool d = dfs(i-1, j);
        bool r = dfs(i, j+1); 
        bool l = dfs(i, j-1);
        return u && d && r && l;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        this->g = grid;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0;  j < n; j++) {
                if (g[i][j] == 0) {
                    res += dfs(i, j);
                }
            }
        }
        return res;
    }
};
