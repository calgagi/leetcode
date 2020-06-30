class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    queue<tuple<int,int,int>> q;
                    unordered_map<int, unordered_map<int,bool>> s;
                    q.push({i, j, 1});
                    while (!q.empty()) {
                        int r = get<0>(q.front());
                        int c = get<1>(q.front());
                        int t = get<2>(q.front());
                        q.pop();
                        t -= 1;
                        if (s[r][c]) continue;
                        s[r][c] = true;
                        if (grid[r][c] < 0) grid[r][c] = max(t, grid[r][c]);
                        else grid[r][c] = t;
                        if (r+1 < grid.size() && (grid[r+1][c] == 1 || grid[r+1][c] < 0))
                            q.push({r+1, c, t});
                        if (c+1 < grid[0].size() && (grid[r][c+1] == 1 || grid[r][c+1] < 0))
                            q.push({r, c+1, t});
                        if (c > 0 && (grid[r][c-1] == 1 || grid[r][c-1] < 0))
                            q.push({r, c-1, t});
                        if (r > 0 && (grid[r-1][c] == 1 || grid[r-1][c] < 0))
                            q.push({r-1, c, t});
                    }
                }
            }
        }
        int m = 0;
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] < 0) m = min(grid[i][j], m);
                else if (grid[i][j] == 1) return -1;
        return abs(m);
        
    }
};
