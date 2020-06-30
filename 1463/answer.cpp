class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n+1][m+2][m+2];
        memset(dp, 0, sizeof(dp));
        for (int row = n-1; row >= 0; row--) {
            for (int robot1 = 1; robot1 <= m; robot1++) {
                for (int robot2 = 1; robot2 <= m; robot2++) {
                    for (int change1 = -1; change1 <= 1; change1++) {
                        for (int change2 = -1; change2 <= 1; change2++) {
                            dp[row][robot1][robot2] = max(
                                dp[row][robot1][robot2],
                                (robot1 == robot2 ? grid[row][robot1-1] : grid[row][robot1-1] + grid[row][robot2-1]) +
                                dp[row+1][robot1+change1][robot2+change2]
                            );
                        }
                    }
                }
            }
        }
        return dp[0][1][m];
    }
};
