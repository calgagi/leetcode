class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        for (int i = 1; i < dp.size(); i++) dp[i][0] = dp[i-1][0] + (int) s1[i-1];
        for (int j = 1; j < dp[0].size(); j++) dp[0][j] = dp[0][j-1] + (int) s2[j-1];
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j] + (int) s1[i-1], dp[i][j-1] + (int) s2[j-1]);
            }
        }
        return dp.back().back();
    }
};
