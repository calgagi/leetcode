class Solution {
public:
    const int M = 1e9+7;
    int dp[51][51][11]; // i = row, j = col, k = cuts
    vector<string> pizza;
    int m, n;
    
    int dfs(int i, int j, int k) {
        if (j >= m || i >= n) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        if (k == 0) {
            for (int r = i; r < n; r++) {
                for (int c = j; c < m; c++) {
                    if (pizza[r][c] == 'A') {
                        dp[i][j][k] = 1;
                        return 1;
                    }
                }
            }
            dp[i][j][k] = 0;
            return 0;
        }
        int ans = 0;
        bool g = 0;
        for (int r = i; r < n; r++) {
            for (int c = j; c < m; c++) {
                if (pizza[r][c] == 'A') {
                    g = 1;
                    break;
                }
            }
            if (g) {
                ans = (ans + dfs(r+1, j, k-1)) % M;
            }
        }
        g = 0;
        for (int c = j; c < m; c++) {
            for (int r = i; r < n; r++) {
                if (pizza[r][c] == 'A') {
                    g = 1;
                    break;
                }
            }
            if (g) {
                ans = (ans + dfs(i, c+1, k-1)) % M;
            }
        }
        dp[i][j][k] = ans;
        return ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        this->pizza = pizza;
        memset(dp, -1, sizeof(dp));
        n = pizza.size(), m = pizza[0].size();
        dfs(0, 0, k-1);

        return dp[0][0][k-1];
    }
};
