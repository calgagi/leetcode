class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        unordered_map<int, unordered_map<int,bool>> seen;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !(seen.count(i) && seen[i].count(j))) {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    int count = 0;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if (seen.count(r) && seen[r].count(c)) continue;
                        count++;
                        seen[r][c] = true;
                        for (int x = 0; x < n; x++)
                            if (grid[x][c] == 1) q.push({x, c});
                        for (int y = 0; y < m; y++)
                            if (grid[r][y] == 1) q.push({r, y});
                    }
                    if (count > 1) res += count;
                }
            }
        }
        return res;
    }
};
