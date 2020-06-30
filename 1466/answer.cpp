class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n-1; i++) {
            graph[c[i][0]].push_back(c[i][1]);
            graph[c[i][1]].push_back(c[i][0]);
        }
        
        vector<int> parent(n, -1);
        queue<pair<int,int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int,int> x = q.front();
            q.pop();
            if (parent[x.first] != -1) {
                continue;
            }
            parent[x.first] = x.second;
            for (int e : graph[x.first]) {
                q.push({e, x.first});
            }
        }
        
        int ans = 0;
        for (vector<int> e : c) {
            if (parent[e[1]] == e[0]) {
                ans++;
            }
        }
        return ans;
    }
};
