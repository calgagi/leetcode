class Solution {
public:
    vector<vector<int>> dp;
    string a, b, c;
    int n, m;
    
    bool helper(int i, int j, int k) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == n && j == m) {
            dp[i][j] = 1;
            return 1;
        }
        dp[i][j] = 0;
        if (i < n && a[i] == c[k]) {
            dp[i][j] |= helper(i+1, j, k+1);
        }
        if (j < m && b[j] == c[k]) {
            dp[i][j] |= helper(i, j+1, k+1);
        }
        return dp[i][j];
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        a = s1, b = s2, c = s3;
        int i = 0, j = 0, k = 0;
        n = s1.length(), m = s2.length();
        dp.assign(n+1, vector<int>(m+1, -1));
        if (n+m != s3.length()) {
            return 0;
        }
        return helper(i, j, k);
    }
};
