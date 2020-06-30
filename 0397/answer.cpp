class Solution {
public:
    map<long long,long long> dp;
    
    long long dfs(long long n) {
        if (dp.count(n)) {
            return dp[n];
        }
        if (n == 1) {
            return 0;
        }
        if ((n&1)) {
            dp[n] = min(dfs(n+1), dfs(n-1))+1;
        } else {
            dp[n] = dfs(n/2)+1;
        }
        return dp[n];
    }
    
    int integerReplacement(int n) {
        return dfs(n);
    }
};
