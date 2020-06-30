class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int res = 0, n = A.size();
        if (n <= 2) {
            return n;
        }
        vector<map<int,int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                dp[j][A[j]-A[i]] = max(dp[j][A[j]-A[i]], dp[i][A[j]-A[i]]+1);
                res = max(res, dp[j][A[j]-A[i]]);
            }
        }
        return res+1;
    }
};
