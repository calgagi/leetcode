class Solution {
public:
    const long long M = 1e9 + 7;
    vector<vector<vector<long long>>> dp;
    int n, m, k;
    
    int dfs(int w, int l, int p) {
        if (w == n) {
            return p == 0;
        }
        if (p < 0 || m - l < p) {
            return 0;
        }
        if (dp[w][l][p] != -1) {
            return dp[w][l][p];
        }
        dp[w][l][p] = 0;
        for (int i = 1; i <= m; i++) {
            dp[w][l][p] = (dp[w][l][p] + dfs(w+1, max(i, l), p - (i > l))) % M;
        }
        return dp[w][l][p];
    }
    
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;
        dp.assign(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, -1)));
        return dfs(0, 0, k);
    }
};
