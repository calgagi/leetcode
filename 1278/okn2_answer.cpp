class Solution {
public:
    int palindromePartition(string str, int k) {
        const int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int L = n-2; L >= 0; L--) {
            for (int R = L+1; R < n; R++) {
                // Check if palindrome
                if (R-L == 1)
                    dp[L][R] = str[L] == str[R] ? 0 : 1;
                else
                    dp[L][R] = str[L] == str[R] ? dp[L+1][R-1] : dp[L+1][R-1] + 1;
            }
        }
        
        vector<vector<int>> dp2(n, vector<int>(k+1, 101));
        for (int i = 0; i < n; i++)
            dp2[i][1] = dp[0][i];
        for (int p = 2; p <= k; p++) {
            for (int R = 1; R < n; R++) {
                for (int M = R-1; M >= 0; M--) {
                    dp2[R][p] = min(dp2[R][p], dp2[M][p-1] + dp[M+1][R]);
                }
            }
        }
        return dp2[n-1][k];
    } 
};
