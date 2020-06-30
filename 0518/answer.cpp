class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, 0));
        for (int i = 0; i < dp[0].size(); i++) dp[0][i] = 1;
        for (int i = 1; i < dp.size(); i++)
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = i-coins[j-1] >= 0 ? dp[i-coins[j-1]][j] + dp[i][j-1] : dp[i][j-1]; 
            }
        return dp[amount][coins.size()];
    }
};
