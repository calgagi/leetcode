class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> c;
        int total;
        for (int i = 0; i < wall.size(); i++) {
            int t = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                t += wall[i][j];
                c[t]++;
            }
            total = t;
        }
        int r = INT_MAX;
        for (auto it = c.begin(); it != c.end(); it++) {
            int x = wall.size() - it->second;
            if (it->first == total) x = wall.size();
            r = min(r, x);
        }
        return r;
    }
};
