class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        // BFS
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        queue<tuple<int,int,int,int>> q;
        q.push({0, 0, 0, 0});
        while (!q.empty()) {
            int i = get<0>(q.front()), j = get<1>(q.front()), p = get<2>(q.front()), c = get<3>(q.front());
            q.pop();
            if (grid[i][j] == 1) p++;
            if (p > k) continue;
            if (memo[i][j][p] != INT_MAX) continue;
            memo[i][j][p] = c;
            if (i == m-1 && j == n-1) return memo[i][j][p];
            if (i > 0) q.push({i-1, j, p, c+1});
            if (j > 0) q.push({i, j-1, p, c+1});
            if (i+1 < m) q.push({i+1, j, p, c+1});
            if (j+1 < n) q.push({i, j+1, p, c+1});
        }
        return -1;
    }
};
