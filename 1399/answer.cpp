class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> m;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int x = i, g = 0;
            while (x) {
                g += x % 10;
                x /= 10;
            }
            m[g]++;
            mx = max(m[g], mx);
        }
        int ans = 0;
        for (auto& p : m) {
            if (p.second == mx) {
                ans++;
            }
        }
        return ans;
    }
};
