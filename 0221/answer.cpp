class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int r = 0;
        vector<vector<int> > dp(n+1, vector(m+1, 0));
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                if (matrix[i-1][j-1] == '1')
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                r = max(dp[i][j], r);
            }
        }
        return pow(r, 2);
    }
};
