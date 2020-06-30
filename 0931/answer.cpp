class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size()-1, vector<int>(A[0].size(), (int)INFINITY));
        // Base case
        dp.insert(dp.begin(), A[0]);
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = dp[i-1][j] + A[i][j];
                if (j > 0) dp[i][j] = min(dp[i-1][j-1] + A[i][j], dp[i][j]);
                if (j < dp[i].size()-1) dp[i][j] = min(dp[i-1][j+1] + A[i][j], dp[i][j]);
            }
        }
        // Find min
        vector<int> r = dp.back();
        int rr = (int)INFINITY;
        for (int i = 0; i < r.size(); i++)
            rr = min(r[i], rr);
        return rr;
    }
};
