class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (str1[i] == str2[j]) {
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
            }
        }
        int i = m, j = n;
        if (dp[i][j] == 0) return str1 + str2;
        string res = "";
        while (i != 0 || j != 0) {
            if (j > 0 && dp[i][j-1] == dp[i][j]) {
                res = str2[j-1] + res;
                j--;
            } else if (i > 0 && dp[i-1][j] == dp[i][j]) { 
                res = str1[i-1] + res;
                i--;
            } else if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1]+1) {
                res = str1[i-1] + res;
                i--, j--;
            } else if (i == 0) {
                res = str2[j] + res;
                j--;
            } else if (j == 0) {
                res = str1[i] + res;
                i--;
            }
        }
        return res;
    }
};
