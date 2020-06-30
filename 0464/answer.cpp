class Solution {
public:
    unordered_map<bool, unordered_map<int, bool>> dp;
    int m;
    
    bool helper(int p, bool player, int cur, int mx) {
        // Return winner
        if (dp.count(player) && dp[player].count(p)) 
            return dp[player][p];
        if (cur >= mx) {
            dp[player][p] = false;
            return false;
        }
        for (int i = 0; i < m; i++) {
            if (!(p & (1 << i))) {
                bool res = !helper(p|(1 << i), !player, cur+i+1, mx);
                if (res) {
                    dp[player][p] = true;
                    return true;
                }
            }
        }
        dp[player][p] = false;
        return false;
    }
    
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        m = maxChoosableInteger;
        if (m * (m+1) / 2 < desiredTotal) return false;
        return helper(0, true, 0, desiredTotal);
    }
};
