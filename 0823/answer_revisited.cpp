class Solution {
public:
    int MOD = pow(10, 9) + 7;
    
    int add(long long a, long long b) {
        return (a + b) % MOD;
    }
    
    int mult(long long a, long long b) {
        return (a * 1LL * b) % MOD;
    }
    
    int numFactoredBinaryTrees(vector<int>& A) {
        // DP?
        sort(A.begin(), A.end());
        unordered_map<int,int> dp;
        dp[A[0]] = 1;
        for(int i = 1; i < A.size(); i++) {
            dp[A[i]] = 1;
            for (int j = 2; j <= sqrt(A[i]); j++)
                if (A[i] % j == 0 && j != sqrt(A[i]))
                    dp[A[i]] = add(dp[A[i]], mult(2,mult(dp[A[i]/j],dp[j])));
                else if (A[i] % j == 0)
                    dp[A[i]] = add(dp[A[i]], mult(dp[A[i]/j],dp[j]));
        }
        int res = 0;
        for (auto& a : A) {
            res = add(res, dp[a]);
        }
        return res;
    }
};
