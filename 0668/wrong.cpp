class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int org_m = m+1, org_n = n+1;
        while (k - (m + (n-1)) > 0) {
            k -= (m + (n-1));
            n--;
            m--;
        }
        if (k > min(m, n)) k -= min(m, n);
        else k /= 2;
        return (org_n - n) * (org_m - m + k); 
    }
};
