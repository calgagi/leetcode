class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> graph;

    int dfs(int src, int dst, int K) {
        if (K == -1 && src != dst)
            return INT_MAX;
        if (src == dst)
            return 0;
        long r = INT_MAX;
        for (auto &e : this->graph[src]) {
            r = min(r, (long) dfs(e.first, dst, K-1) + (long) e.second);
        }
        if (r >= INT_MAX) return INT_MAX;
        return r;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for (auto &e : flights) {
            this->graph[e[0]].push_back({e[1], e[2]});
        }
        int res = dfs(src, dst, K);
        return res == INT_MAX ? -1 : res;
    }
};
