class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> dp;
    vector<int> stones;
    const int M = -1e9;
    
    pair<int,int> dfs(int i, bool t) {
        //cout << i << " " << t << endl;
        if (i >= n) {
            return {0, 0};
        } else if (dp[i][t].first != M) {
            return dp[i][t];
        }
        int val = 0;
        pair<int,int> res = {M, M};
        for (int j = 0; j < 3 && i+j < n; j++) {
            val += stones[i+j];
            pair<int,int> x = dfs(i+j+1, !t);
            if (t && x.first+val > res.first) {
                res = {x.first+val, x.second};
            } else if (!t && x.second+val > res.second) {
                res = {x.first, x.second+val};
            }
        }
        dp[i][t] = res;
        return res;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        stones = stoneValue;
        dp.assign(n, vector<pair<int,int>>(2, {M,M}));
        pair<int,int> r = dfs(0, 1);
        /*
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                cout << dp[i][j].first << "," << dp[i][j].second << " ";
            }
            cout << endl;
        }
        */
        if (r.first == r.second) {
            return "Tie";
        }
        return (r.first < r.second ? "Bob" : "Alice");
    }
};
