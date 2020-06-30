class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<long>> dpH(grid.size(), vector<long>(grid[0].size(), INT_MAX));
        vector<vector<long>> dpV(grid.size(), vector<long>(grid[0].size(), INT_MAX));
        dpH[0][0] = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) continue;
                if (i-1 >= 0 && !grid[i-1][j]) {
                    dpV[i][j] = min(dpV[i][j], dpV[i-1][j]+1);
                }
                if (j-1 >= 0 && !grid[i][j-1]) {
                    dpH[i][j] = min(dpH[i][j], dpH[i][j-1]+1);
                }
                if (i+1 < r && j+1 < c && !grid[i+1][j] && !grid[i+1][j+1] && !grid[i][j+1]) {
                    dpH[i+1][j] = min(dpH[i+1][j], dpH[i][j]+1);
                    dpV[i][j+1] = min(dpV[i][j+1], dpV[i][j]+1);
                    dpH[i][j] = min(dpH[i][j], dpV[i][j]+1);
                    dpV[i][j] = min(dpV[i][j], dpH[i][j]+1);
                }
            }
        }
        int x = min(dpV.back().back(), dpH.back().back());
        if (x >= INT_MAX) return -1;
        else return x;
    }
};
