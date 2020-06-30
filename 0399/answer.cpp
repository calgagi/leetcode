class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> e;
        vector<double> r;
        for (int i = 0; i < equations.size(); i++) {
            if (e.find(equations[i][0]) == e.end()) 
                e[equations[i][0]] = unordered_map<string, double>();
            if (e.find(equations[i][1]) == e.end()) 
                e[equations[i][1]] = unordered_map<string, double>();
            e[equations[i][0]][equations[i][1]] = values[i];
            if (values[i] != 0)
                e[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        
        for (int i = 0; i < queries.size(); i++) {
            if (e.find(queries[i][0]) == e.end() || e.find(queries[i][0]) == e.end()) {
                r.push_back(-1.0);
                continue;
            } 
            
            // BFS
            bool found = false;
            unordered_set<string> seen = { queries[i][0] };
            queue<pair<string, double>> dfs;
            dfs.push(make_pair(queries[i][0], 1.0));
            while (!dfs.empty()) {
                pair<string, double> n = dfs.front(); dfs.pop();
                if (n.first == queries[i][1]) {
                    r.push_back(n.second); 
                    found = true;
                    break;
                }
                for (auto it = e[n.first].begin(); it != e[n.first].end(); ++it) {
                    if (seen.find(it->first) == seen.end()) {
                        seen.insert(it->first);
                        dfs.push(make_pair(it->first, it->second * n.second));
                    }
                }
            }
            if (!found) {
                r.push_back(-1.0);
            }
        }
        
        return r;
    }
};
