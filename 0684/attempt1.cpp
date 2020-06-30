class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Create graph
        vector<vector<int> > graph(edges.size()+1, vector<int>(edges.size()+1, 0));
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
        }
        stack<pair<int,int> > s;
        s.push({edges[0][0], edges[0][1]});
        unordered_set<int> v;
        vector<int> r;
        while (!s.empty()) {
            int parent = s.top().first;
            int child = s.top().second;
            s.pop();
            v.insert(child);
            bool found = false;
            for (int i = 0; i < graph[child].size(); i++)
                if (graph[child][i] && v.find(child) == v.end()) {
                    found = true;
                    s.push({child, i});
                }
            if (!found) {
                r.push_back(parent);
                r.push_back(child);
                break;
            }
        }
        for (int i = 0; i < edges.size(); i++)
            if (r[0] == edges[i][0] && r[1] == edges[i][1]) return r;
        reverse(r.begin(), r.end());
        return r;
    }
};
