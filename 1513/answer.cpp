class Solution {
public:
    int numSub(string s) {
        const int M = 1e9+7;
        int streak = 0, ans = 0;
        for (int i = 0; i < (int) s.length(); i++) {
            if (s[i] == '1') {
                streak++;
            } else {
                streak = 0;
            }
            ans = (ans + streak) % M;
        }
        return ans;
    }
};
