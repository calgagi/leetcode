class Solution {
public:
    const int M = 1e9+7;
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].length();
        vector<vector<pair<int,int>>> dp(m+1, vector<pair<int,int>>(n+1, {0,0}));
        dp[m][n] = {0,1};
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') {
                    continue;
                }
                int add = (board[i][j] <= '9' && board[i][j] >= '0' ? board[i][j] - '0' : 0);
                int mx = max({dp[i+1][j].first, dp[i+1][j+1].first, dp[i][j+1].first});
                dp[i][j].first = mx + add;
                for (pair<int,int> dir : vector<pair<int,int>>({{1, 0}, {1, 1}, {0,1}})) {
                    if (dp[i+dir.first][j+dir.second].first == mx) {
                        dp[i][j].second = (dp[i+dir.first][j+dir.second].second + dp[i][j].second) % M;
                    }
                }
            }
        }
        return {(dp[0][0].second == 0 ? 0 : dp[0][0].first), dp[0][0].second};
    }
};
