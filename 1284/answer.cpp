class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        // DP?
        const int n = mat.size(), m = mat[0].size();
        // Convert to string for state
        unordered_map<string, bool> dp;
        string cur = "";
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cur += to_string(mat[i][j]);
        // BFS
        queue<pair<string, int>> q;
        q.push({cur, 0});
        while (!q.empty()) {
            int steps = q.front().second;
            string state = q.front().first;
            q.pop();
            if (dp.count(state)) continue;
            dp[state] = true;
            bool one = false;
            for (int i = 0; i < n*m; i++) {
                if (state[i] == '1') {
                    int left = (i-1)/m == i/m ? i-1 : -1;
                    int right = (i+1)/m == i/m ? i+1 : -1;
                    int above = i-m >= 0 ? i-m : -1;
                    int below = i+m < n*m ? i+m : -1;
                    vector<int> x = {left, right, below, above, i};
                    for (auto& y : x) {
                        if (y != -1) {
                            string s = state;
                            s[y] = s[y] == '1' ? '0' : '1';
                            int l = (y-1)/m == y/m ? y-1 : -1;
                            int r = (y+1)/m == y/m ? y+1 : -1;
                            int a = y-m >= 0 ? y-m : -1;
                            int b = y+m < n*m ? y+m : -1;
                            if (l != -1) s[l] = s[l] == '1' ? '0' : '1';
                            if (r != -1) s[r] = s[r] == '1' ? '0' : '1';
                            if (a != -1) s[a] = s[a] == '1' ? '0' : '1';
                            if (b != -1) s[b] = s[b] == '1' ? '0' : '1';
                            q.push({s, steps+1});
                        }
                    }
                    one = true;
                }
            }
            if (!one) return steps;
        }
        return -1;
    }
};
