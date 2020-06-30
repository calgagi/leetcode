class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<bool> apple;
    vector<bool> visited;

    int dfs(int u) {
        if (visited[u]) {
            return 0;
        }
        visited[u] = 1;
        int dist = 0;
        for (int& v : graph[u]) {
            dist += dfs(v);
        }
        if (apple[u] || dist) {
            dist++;
        }
        return dist;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        apple = hasApple;
        graph.resize(n);
        this->n = n;
        visited.assign(n, 0);
        
        for (vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int ans = 2*dfs(0);
        if (ans == 0) {
            return 0;
        }
        return ans-2;
    }
};
