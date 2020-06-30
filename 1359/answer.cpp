class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int countOrders(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * (i * 2 - 1) * i) % MOD;
        }
        return (int) res;
    }
};
