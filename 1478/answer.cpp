class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        vector<vector<int>> cost(n, vector<int>(n));
        sort(houses.begin(), houses.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int median = (i+j) / 2;
                cost[i][j] = 0;
                for (int l = i; l <= j; l++) {
                    cost[i][j] += abs(houses[median] - houses[l]);
                }
            }   
        }
        
        vector<vector<int>> dp(k, vector<int>(n+1, (int) 1e9));
        for (int i = 0; i < n; i++) {
            dp[0][i] = cost[0][i];
        }
        
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < j; l++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][l] + cost[l+1][j]);
                }
            }
        }
        
        return dp[k-1][n-1];
    }
};
