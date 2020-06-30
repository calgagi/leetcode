class Solution {
public:
    vector<int> dp;
    
    int dfs(vector<vector<int>>& g, int s) {
        if (dp[s] != -1) {
            return dp[s];
        }
        int res = 1;
        for (auto& j : g[s]) {
            res = max(dfs(g, j)+1, res);
        }
        dp[s] = res;
        return res;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> graph(n);
        dp.assign(n,  -1);

        for (int i = 0; i < n; i++)  {
            int x = 1;
            while (x <= d && i-x >= 0 && arr[i-x] < arr[i]) {
                graph[i].push_back(i-x);
                x++;
            }
            x = 1;
            while (x <= d && i+x < n && arr[i+x] < arr[i]) {
                graph[i].push_back(i+x);
                x++;
            }
        }
        // dfs
        int best = 1;
        for (int i = 0; i < n; i++) {
            best = max(best, dfs(graph, i));
        }
        return best;
    }
};
