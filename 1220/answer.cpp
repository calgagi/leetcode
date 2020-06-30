class Solution {
public:
    
    int MOD = 7 + pow(10, 9);
    
    int add(long a, long b) {
        return (a + b) % MOD;
    }
    
    int countVowelPermutation(int n) {
        vector<int> a(n+1), e(n+1), i(n+1), o(n+1), u(n+1);
        a[1] = e[1] = i[1] = o[1] = u[1] = 1;
        for (int j = 2; j <= n; j++) {
            e[j] = add(a[j-1], i[j-1]);
            a[j] = add(add(e[j-1], u[j-1]), i[j-1]);
            i[j] = add(e[j-1], o[j-1]);
            o[j] = i[j-1];
            u[j] = add(o[j-1], i[j-1]);
        }
        return add(e[n], add(a[n], add(i[n], add(o[n], u[n]))));
    }
};
