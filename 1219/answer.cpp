class Solution {
public:
    
    int z = 0;
    
    void dfs(vector<vector<int>>& grid, int r, int c, int& t) {
        t += grid[r][c];
        z = max(z, t);
        int b = grid[r][c];
        grid[r][c] = 0;
        if (r+1 < grid.size() && grid[r+1][c]) 
            dfs(grid, r+1, c, t);
        if (r-1 >= 0 && grid[r-1][c])
            dfs(grid, r-1, c, t);
        if (c+1 < grid[0].size() && grid[r][c+1])
            dfs(grid, r, c+1, t);
        if (c-1 >= 0 && grid[r][c-1])
            dfs(grid, r, c-1, t);
        grid[r][c] = b;
        t -= b;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int t = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) dfs(grid, i, j, t);
            }
        }
        return z;
    }
};
