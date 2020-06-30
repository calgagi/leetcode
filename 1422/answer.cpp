class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> right(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                right[i]++;
            }
            right[i] += right[i+1];
        }
        int ans = 0, left = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') {
                left++;
            }
            ans = max(ans, left+right[i+1]);
        }
        return ans;
    }
};
