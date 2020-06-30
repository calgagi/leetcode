class Solution {
public:
    int test(vector<int>& b, int k, int m) {
        int n = b.size(), ans = 0, streak = 0;
        
        for (int i = 0; i < n; i++) {
            if (b[i] <= m) {
                streak++;
            } else {
                streak = 0;
            }
            if (streak == k) {
                ans++;
                streak = 0;
            }
        }
        
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int n, int k) {
        if (bloomDay.size() / k < n) {
            return -1;
        }
        
        int l = 1, r = 1e9, ans = r;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (n <= test(bloomDay, k, m)) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        
        return ans;
    }
};
