const int N = 300 + 10;
int cost[26][26];
int dp[N][N];

class Solution {
public:
    string word;
    
    int solve(int x, int y) {
        const int n = word.length();
        int where = max(x, y)+1;
        if (where >= n) {
            return 0;
        }
        if (dp[x][y] >= 0) {
            return dp[x][y];
        }
        int res = solve(where, y) + cost[word[x]-'A'][word[where]-'A'];
        res = min(res, solve(x, where) + cost[word[y]-'A'][word[where]-'A']);
        dp[x][y] = res;
        return res;
    }
    
    int minimumDistance(string word) {
        this->word = word;
        const int n = word.length();
        memset(dp, 255, sizeof(dp));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                cost[i][j] = abs(i/6-j/6) + abs(i%6-j%6);
            }
        }
        int res = 0, best = INT_MAX;
        for (int i = 1; i < n; i++) {
            best = min(solve(i-1, i)+res, best);
            res += cost[word[i-1]-'A'][word[i]-'A'];
        }
        return best;
    }
};
