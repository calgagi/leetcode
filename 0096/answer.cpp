class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++) {
            cout << i << endl;
            for (int j = i-1, k = 0; j >= i/2; j--, k++) {
                dp[i] += (dp[j] * dp[k])*2;
            }
            if (i % 2 == 1) dp[i] -= dp[i/2]*dp[i/2];
        }
        return dp[n];
    }
};
