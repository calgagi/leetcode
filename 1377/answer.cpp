class Solution {
public:
    vector<vector<int>> graph; 
    vector<double> p;
    
    void dfs(int cur, double prob, int time, int target) {
        if (p[cur] != 0) {
            return;
        }
        if (time >= 0 && target == cur && graph[cur].size() == 1) {
            p[cur] = prob;
            return;
        } else if ((time == 0 && target != cur) || (cur == target && time != 0)) {
            return;
        }
        p[cur] = prob;
        int n = graph[cur].size();
        for (int i = 0; i < n; i++) {
            dfs(graph[cur][i], prob/((double)n-1.0), time-1, target);   
        }
        return;
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        graph.resize(n);
        p.assign(n, 0.0);
        graph[0].push_back(0);
        for (int i = 0; i < (int) edges.size(); i++) {
            edges[i][0]--, edges[i][1]--;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, 1.0, t, target-1);
        return p[target-1];
    }
};
