class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        int goal = (1 << n) - 1;
        bool dp[goal][n] = {0};
        queue<tuple<int,int,int>> q;
        for (int i = 0; i < n; i++)
            q.emplace(0, i, 0);
        while (!q.empty()) {
            int visited = get<0>(q.front());
            int vertex = get<1>(q.front());
            int path_len = get<2>(q.front());
            q.pop();
            visited |= (1 << vertex);
            if (visited == goal) return path_len;
            if (dp[visited][vertex]) continue;
            dp[visited][vertex] = 1;
            for (auto& e : graph[vertex]) {
                q.emplace(visited, e, path_len+1);
            }
        }
        return INT_MAX;
    } 
};
