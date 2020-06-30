class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        vector<vector<bool>> dp(s.size()+1, vector<bool>(s.size()+1, false));
        int x = 0, y = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i][i] = true;
            if (i < dp.size()-1 && s[i-1] == s[i]) {
                dp[i+1][i] = true;
                dp[i][i+1] = true;
                if (x-y < i-(i-1)) {
                    x = i;
                    y = i-1;
                }
            }
            for (int j = i-1; j > 0; j--) {
                if (s[i-1] == s[j-1]) {
                    if (dp[j+1][i-1] == true) {
                        dp[j][i] = true;
                        if (x-y < i-j) {
                            x = i-1;
                            y = j-1;
                        }
                    }
                }
            }
        }
        string r = "";
        for (int i = y; i <= x; i++) r += s[i];
        return r;
    }
};
