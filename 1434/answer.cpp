class Solution {
public:
    int n;
    const int MAX_H = 41;
    const int MAX_N = 10;
    const int M = 1e9+7;

    vector<vector<int>> phats;
    vector<vector<int>> dp;
    
    int dfs(int hat, int assigned) {
        if (dp[hat][assigned] != -1) {
            return dp[hat][assigned];
        }
        dp[hat][assigned] = 0;
        for (auto& person : phats[hat]) {
            if ((assigned & (1 << person))) {
                continue;
            }
            int assigned2 = (assigned | (1 << person));
            if (assigned2 == (1 << n)-1) {
                dp[hat][assigned]++;
                continue;
            }
            for (int i = hat+1; i < MAX_H; i++) {
                dp[hat][assigned] = (dp[hat][assigned] + dfs(i, assigned2)) % M;
            }  
        }
        //cout << hat << " " << assigned << " " << dp[hat][assigned] << endl;
        return dp[hat][assigned];
    }
    
    int numberWays(vector<vector<int>>& hats) {
        dp.assign(MAX_H, vector<int>(1 << MAX_N, -1));
        phats.resize(MAX_H);
        
        n = hats.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) hats[i].size(); j++) {
                phats[hats[i][j]].push_back(i);
            }
        }
        
        int ans = 0;
        for (int i = 1; i < MAX_H; i++) {
            ans = (ans + dfs(i, 0)) % M;
        }
        return ans;
    }
};
