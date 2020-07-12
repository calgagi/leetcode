class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < (int) edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double,int>> q;
        q.push({1.0, start});
        vector<double> prob(n, -1);
        while (!q.empty()) {
            pair<double,int> c = q.top();
            q.pop();
            if (prob[c.second] != -1) {
                continue;
            }
            prob[c.second] = c.first;
            for (pair<int, double>& e : graph[c.second]) {
                q.push({c.first * e.second, e.first});
            }
        }
        return (prob[end] == -1 ? 0 : prob[end]);
    }
};
