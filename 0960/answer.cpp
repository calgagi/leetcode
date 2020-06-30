class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int n = A.size(), m = A[0].length();
        vector<int> dp(m, 1);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                int k;
                for (k = 0; k < n; k++) {
                    if (A[k][i] < A[k][j]) {
                        break;
                    }
                }
                if (k == n)
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return m-res;
    }
};
