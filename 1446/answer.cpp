class Solution {
public:
    int maxPower(string s) {
        int ans = 1, streak = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                streak++;
            } else {
                streak = 1;
            }
            ans = max(streak, ans);
        }
        return ans;
    }
};
