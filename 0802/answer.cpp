class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> g(graph.size());
        vector<int> c(graph.size()); 
        queue<int> q;
        for (int i = 0; i < graph.size(); i++) {
            for (int &p : graph[i]) {
                g[p].push_back(i);
            }
            c[i] = graph[i].size();
            if (!c[i]) q.push(i); 
        }
        vector<int> r;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            r.push_back(t);
            for (int i = 0; i < g[t].size(); i++) {
                c[g[t][i]]--; 
                if (!c[g[t][i]]) q.push(g[t][i]);
            }
        }
        sort(r.begin(), r.end());
        return r;
    }
};
