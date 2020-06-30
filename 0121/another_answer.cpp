class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()+1];
        dp[0] = 0; 
        int cm = (int) INFINITY;
        for (int i = 1; i < prices.size()+1; i++) {
            cm = min(cm, prices[i-1]);
            dp[i] = max(dp[i-1], prices[i-1]-cm);
        }
        return dp[prices.size()];
    }
};
