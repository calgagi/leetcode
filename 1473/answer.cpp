class Solution {
public:
    int target;
    vector<vector<int>> cost;
    vector<int> houses;
    int m, n;
    int INF = 1e9+7;
    
    vector<vector<vector<int>>> dp;
    
    int dfs(int where, int prev_color, int neighborhoods) {    
        if (where == m && neighborhoods == target) {
            return 0;
        }
        else if (neighborhoods > target || where >= m) {
            return INF;
        }
        
        if (dp[where][prev_color][neighborhoods] != -1) {
            return dp[where][prev_color][neighborhoods];
        }
        
        dp[where][prev_color][neighborhoods] = INF;
        
        if (houses[where] != 0) {
            dp[where][prev_color][neighborhoods] = dfs(where+1, houses[where], neighborhoods + (prev_color != houses[where]));
        }
        else {       
            for (int i = 0; i < n; i++) {
                dp[where][prev_color][neighborhoods] = min(
                    dp[where][prev_color][neighborhoods],
                    cost[where][i] + dfs(where+1, i+1, neighborhoods + (prev_color != i+1))
                );
            }
        }
        return dp[where][prev_color][neighborhoods];
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.assign(m, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        
        this->m = m, this->n = n;
        this->houses = houses;
        this->cost = cost;
        this->target = target;
        
        int ans = dfs(0, 0, 0);
        
        return (ans == INF ? -1 : ans);
    }
};
