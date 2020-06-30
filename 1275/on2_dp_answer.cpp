class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Prefix?
        vector<vector<int>> dp = matrix;
        int res = 0;

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + (i>0&&j>0?min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])):0);
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
