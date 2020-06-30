class Solution {
public:
    int MOD = pow(10, 9) + 7;
    
    int add(long long a, long long b) {
        return (a + b) % MOD;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(1+steps/2, arrLen);
        if (arrLen == 1) return 1;
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; i++) {
            vector<int> new_dp(arrLen, 0);
            new_dp[0] = add(dp[0], dp[1]);
            new_dp[arrLen-1] = add(dp[arrLen-1], dp[arrLen-2]);
            for (int j = 1; j < arrLen-1; j++) {
                new_dp[j] = add(add(dp[j-1], dp[j]), dp[j+1]);
            }
            dp = new_dp;
        }
        return dp[0];
    }
};
