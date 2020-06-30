class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N >= K+W-1) return 1.0;
        vector<double> dp(K+W, 0);
        double p = (double) 1 / (double) W;
        
        double so_far = 0;
        
        dp[0] = 1;
        
        for (int i = 1; i <= K; i++) {
            so_far -= (i-W-1 >= 0 ? dp[i-W-1] : 0);
            so_far += dp[i-1];
            dp[i] = so_far * p;
        }
        
        double res = dp[K];
        for (int i = K+1; i <= N; i++) {
            so_far -= (i-W-1 >= 0 ? dp[i-W-1] : 0);
            dp[i] = so_far * p;
            res += dp[i];
        }
        
        return res;
    }
};
