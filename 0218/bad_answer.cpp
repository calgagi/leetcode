class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        if (buildings.size() == 0) {
            return res;
        }
        vector<vector<int>> hb = buildings;
        for (int i = 0; i < (int) buildings.size(); i++) {
            auto& b = hb[i];
            swap(b[0], b[2]);
            swap(b[1], b[2]);
            b.push_back(i);
            b[0] = -b[0];
        }
        sort(hb.begin(), hb.end());
        int MAX_R = 0;
        for (auto& b : hb) {
            b[0] = -b[0];
            MAX_R = max(MAX_R, b[2]);
        }
        map<long, long> left;
        buildings.push_back({0, -2, -1, buildings.size()-1});
        left[INT_MAX+2] = left[-INT_MAX-2] = buildings.size()-1;
        for (auto& b : hb) {
            int h = b[0], l = b[1], r = b[2], j = b[3];
            auto to_left = left.lower_bound(l);
            int i = to_left->second;
            if ((l >= buildings[i][0] && r <= buildings[i][1]) || (buildings[i][2] == h && buildings[i][1] >= l)) {
                left[r] = j;
                continue;
            }
            int p = l < buildings[i][0] || l > buildings[i][1] ? l : buildings[i][1];
            left[r] = j;
            res.push_back({p, h, r});
        }
        sort(res.begin(), res.end());
        int n = res.size()-1;
        res.push_back({MAX_R, 0, 0});
        for (int i = 0; i < n; i++) {
            if (res[i][2] < res[i+1][0]) {
                res.push_back({res[i][2], 0, 0});
            }
        }
        for (int i = 0; i < res.size(); i++) {
            res[i].pop_back();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
