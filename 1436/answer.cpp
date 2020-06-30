class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> g;
        for (auto& p : paths) {
            g[p[0]].push_back(p[1]);
        }
        string ans = paths[0][0];
        while (!g[ans].empty()) {
            ans = g[ans][0];
        }
        return ans;
    }
};
