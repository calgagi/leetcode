class Solution {
public:
    const int M = 1e9 + 7;
    int dp[5000+1][4][4][4] = {0};
    
    int dfs(int n, int a, int b, int c) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][a][b][c] != 0) {
            return dp[n][a][b][c];
        }
        int ans = 0;
        for (int i = 1; i <= 3; i++) {
            if (a == i) {
                continue;
            }
            for (int j = 1; j <= 3; j++) {
                if (i == j || j == b) {
                    continue;
                }
                for (int k = 1; k <= 3; k++) {
                    if (k == j || k == c) {
                        continue;
                    }
                    ans = (ans + dfs(n - 1, i, j, k)) % M;
                }
            }
        }
        dp[n][a][b][c] = ans;
        return ans;
    }
    
    int numOfWays(int n) {
        return dfs(n, 0, 0, 0);
    }
};
