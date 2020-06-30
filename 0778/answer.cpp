class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // find maximum value in path
        const int m = grid.size(), n = grid[0].size();
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> fringe;
        fringe.push(grid[0][0]);
        vector<pair<int,int>> where(m * n);
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                where[grid[i][j]] = {i, j};
        while (!fringe.empty()) {
            while (!fringe.empty() && fringe.top() <= res) {
                pair<int,int> coord = where[fringe.top()];
                fringe.pop();
                if (coord.first == m-1 && coord.second == n-1)
                    return res;
                grid[coord.first][coord.second] = -1;
                if (coord.first > 0 && grid[coord.first-1][coord.second] != -1) 
                    fringe.push(grid[coord.first-1][coord.second]);
                if (coord.first < m-1 && grid[coord.first+1][coord.second] != -1)
                    fringe.push(grid[coord.first+1][coord.second]);
                if (coord.second > 0 && grid[coord.first][coord.second-1] != -1) 
                    fringe.push(grid[coord.first][coord.second-1]);
                if (coord.second < n-1 && grid[coord.first][coord.second+1] != -1)
                    fringe.push(grid[coord.first][coord.second+1]);
            }
            res++;
        }
        return -1;
    }
};
