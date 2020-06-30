class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][i] = 1;
            for (int j = i-1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    dp[j][i] = dp[j+1][i-1] + 2;
                } else {
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
                }
            }
        }
        
        return dp[0].back();
    }
};
