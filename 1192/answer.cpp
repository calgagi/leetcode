class Solution {
public:
    
    stack<int> s;
    
    vector<int> low, ids, instack;
    
    unordered_map<int, vector<int>> graph;
    int id;
    
    void dfs(int cur, int parent) {
        s.push(cur);
        instack[cur] = 1;
        low[cur] = ids[cur] = id++;
         
        for (int &to : graph[cur]) {
            if (to == parent) continue;
            if (ids[to] == -1) dfs(to, cur);
            if (instack[to]) low[cur] = min(low[cur], low[to]);
        }
        
        if (ids[cur] == low[cur]) {
            while (!s.empty()) {
                int x = s.top(); s.pop();
                instack[x] = 0;
                low[x] = ids[cur];
                if (x == cur) break;
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        id = 0;
        low.resize(n, INT_MAX);
        ids.resize(n, -1);
        instack.resize(n, 0);
        for (vector<int>& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        dfs(0, -1);
        
        vector<vector<int>> r;
        for (int i = 0; i < connections.size(); i++) {
            if (low[connections[i][0]] > ids[connections[i][1]] || low[connections[i][1]] > ids[connections[i][0]])
                r.push_back(connections[i]);
        }
        return r;
    }
};
