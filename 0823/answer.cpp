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
        sort(A.begin(), A.end());
        unordered_map<int,int> dp;
        int res = 0;
        for (auto& a : A) dp[a] = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    dp[A[i]] = add(dp[A[i]], mult(dp[A[j]], dp[A[i] / A[j]]));
                }
            }
            res = add(res, dp[A[i]]);
        }
        return res;
    }
};
