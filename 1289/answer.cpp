class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> arr;
    const int M = 1e9;
    int n;
    
    int dfs(int r, int c) {
        if (r == n) {
            return 0;
        }
        if (dp[r][c] != M) {
            return dp[r][c];
        }
        for (int i = 0; i < n; i++) {
            if (i == c) {
                continue;
            }
            dp[r][c] = min(dfs(r+1, i)+arr[r][i], dp[r][c]);   
        }
        return dp[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        this->arr = arr;
        n = arr.size();
        dp.assign(n, vector<int>(n, M));
        for (int i = 0; i < n; i++) {
            dp[0][i] = dfs(1, i)+arr[0][i];
        }
        int res = M;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[0][i]);
        } 
        return res;
    }
};
