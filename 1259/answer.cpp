class Solution {
public:
    int MOD = 1e9 + 7;
    
    int add(long a, long b) {
        return (a + b) % MOD;
    }
    
    int mult(long a, long b) {
        return (a * 1LL * b) % MOD;
    }
    
    int numberOfWays(int num_people) {
        vector<int> dp(num_people/2+1, 0);
        dp[0] = 1;
        for(int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = add(dp[i], mult(dp[j], dp[i-j-1]));
            }
        }
        return dp[num_people/2];
    }
};
