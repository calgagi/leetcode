class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    
    int dijkstra(int s, int d) {
        vector<bool> visited(graph.size(), 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int res = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            if (p.first > d || visited[p.second]) {
                continue;
            }
            visited[p.second] = 1;
            for (auto& e : graph[p.second]) {
                pq.push({p.first + e.second, e.first});
            }
            res++;
        }
        return res-1;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        graph.resize(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        int res = 0, m = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = dijkstra(i, distanceThreshold);
            if (m >= x) {
                m = x;
                res = i;
            }
        }
        return res;
    }
};
