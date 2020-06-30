class Solution {
public:
    vector<vector<int>> dp;
    const int MAX_J = 3000000;
    
    int dfs(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n == 0 && d == 0) {
            return 0;
        }
        if (d < 0) {
            return MAX_J;
        }
        if (n < d) {
            dp[n][d] = MAX_J;
        } else {
            if (dp[n][d] != MAX_J) {
                return dp[n][d];
            }
            int c = -1;
            vector<int> save = jobDifficulty;
            for (int i = n-1; i >= 0; i--) {
                c = max(jobDifficulty[i], c);
                jobDifficulty.pop_back();
                dp[n][d] = min(dp[n][d], dfs(jobDifficulty, d-1) + c);
            }
            jobDifficulty = save;
        }
        return dp[n][d];
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        dp.assign(1005, vector<int>(13, MAX_J));
        return dfs(jobDifficulty, d);
    }
};
