class Solution {
public:
    const int M = 1e9 + 7;
    vector<int> dp;
    
    int dfs(const string& s, long long k, int w) {
        if (dp[w] != -1) {
            return dp[w];
        }
        int ans = 0, n = s.length();
        string cur = "";
        for (int i = w; i < n; i++) {
            cur += s[i];
            if (cur == "0" || cur.length() >= 12 || stoll(cur) > k) {
                break;
            }
            ans = (ans + dfs(s, k, i + 1)) % M;
        }
        dp[w] = ans;
        return dp[w];
    }
    
    int numberOfArrays(string s, int k) {
        dp.assign(s.length() + 1, -1);
        dp[s.length()] = 1; 
        return dfs(s, k, 0);
    }
};
