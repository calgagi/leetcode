class Solution {
public:
    
    struct compare {
        bool operator()(tuple<int,int,int>& t1, tuple<int,int,int>& t2) {
            return get<0>(t1) > get<0>(t2);
        }
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        // Dijkstra
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> pq;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            int d = get<0>(pq.top());
            int e = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
            if (e == dst) return d;
            if (j > K) continue;
            for (auto& edge : graph[e]) {
                int b = edge.first, w = edge.second;
                pq.push({d+w, b, j+1});
            }
        }
        return -1;
        
    }
};
