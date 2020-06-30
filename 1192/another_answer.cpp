class Solution {
public:
    
    vector<vector<int> > graph;

    vector<bool> visited;
    vector<int> tin, low;
    int timer;
    vector<vector<int>> r;


    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (int to : graph[v]) {
            if (to == p) continue;
            else if (visited[to]) low[v] = min(low[v], tin[to]);
            else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v])
                    r.push_back({v, to});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        timer = 0;
        visited.assign(graph.size(), false);
        tin.assign(graph.size(), -1);
        low.assign(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
            if (!visited[i]) dfs(i);
        return r;
    }
};
