class Solution {
public:
    int minInsertions(string s) {
        // LCS?
        const int n = s.length();
        string l = s, r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(l.size(), vector<int>(r.size(), 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (l[i] == r[j]) {
                    dp[i][j] = (i>0&&j>0?dp[i-1][j-1]:0)+1;
                } else {
                    dp[i][j] = max((i>0?dp[i-1][j]:0), (j>0?dp[i][j-1]:0));
                }
            }
        }
        return n - dp[n-1][n-1];
    }
};
