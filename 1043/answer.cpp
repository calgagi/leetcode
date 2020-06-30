class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            int curMax = 0;
            for (int j = 1; j <= K && i - j + 1 >= 0; j++) {
                curMax = max(curMax, A[i - j + 1]);
                int z = i >= j ? dp[i - j] : 0;
                dp[i] = max(dp[i], z + curMax * j);
            }
        }
        return dp.back();
        
    }
};
