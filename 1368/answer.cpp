class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<pair<int,int>,int>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({0, {0, 0}});
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> v(n, vector<bool>(m, 0));
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int r = q.top().second.first, c = q.top().second.second, p = q.top().first;
            q.pop();
            if (r < 0 || r >= n || c >= m || c < 0 || v[r][c]) {
                continue;
            }
            if (r == n-1 && c == m-1) {
                return p;
            }
            v[r][c] = 1;
            for (int i = 0; i < 4; i++) {
                if (grid[r][c] == i+1) {
                    q.push({p, {r+dir[i][0], c+dir[i][1]}});
                } else {
                    q.push({p+1, {r+dir[i][0], c+dir[i][1]}});
                }
            }
        }
        return -1;
    }
};
