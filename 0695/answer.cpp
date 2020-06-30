class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int c = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j}); grid[i][j] = -1;
                    while (!q.empty()) {
                        pair<int,int> t = q.front(); q.pop();
                        c++;
                        int x = t.first, y = t.second;
                        if (x > 0 && grid[x-1][y] == 1) {
                            q.push({x-1, y});
                            grid[x-1][y] = -1;
                        }
                        if (x < grid.size()-1 && grid[x+1][y] == 1){
                            q.push({x+1, y});
                            grid[x+1][y] = -1;
                        }
                        if (y > 0 && grid[x][y-1] == 1) {
                            q.push({x, y-1});
                            grid[x][y-1] = -1;
                        }
                        if (y < grid[0].size()-1 && grid[x][y+1] == 1) {
                            q.push({x, y+1});
                            grid[x][y+1] = -1;
                        }
                    }
                    r = max(c, r);
                }
            }
        }
        return r;
    }
};
