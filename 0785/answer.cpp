class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Two color?
        vector<int> colors(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] != -1) continue;
            stack<pair<int, bool>> s;
            s.push({i, true});
            while (!s.empty()) {
                int x = s.top().first; 
                bool c = s.top().second;
                s.pop();
                if (colors[x] == (int) c)
                    continue;
                else if (colors[x] == -1)
                    colors[x] = (int) c;
                else return false;
                for (int i = 0; i < graph[x].size(); i++) {
                    s.push({graph[x][i], !c});
                }
            }    
        }
        return true;
    }
};
