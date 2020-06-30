class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // DP?
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        // O((m*n)^2)
        int dp[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = 1;
        
        int res = 1, count = 1;
        while (count) {
            count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int save = dp[i][j];
                    if (i>0 && matrix[i-1][j] < matrix[i][j])
                        dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
                    if (j>0 && matrix[i][j-1] < matrix[i][j])
                        dp[i][j] = max(dp[i][j], dp[i][j-1]+1);
                    if (j<n-1 && matrix[i][j+1] < matrix[i][j])
                        dp[i][j] = max(dp[i][j], dp[i][j+1]+1);
                    if (i<m-1 && matrix[i+1][j] < matrix[i][j])
                        dp[i][j] = max(dp[i][j], dp[i+1][j]+1);
                    if (save != dp[i][j]) count++;
                    res = max(dp[i][j], res);
                }
            }
        }
        return res;
    }
};
