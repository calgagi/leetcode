ass Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& x) {
        vector<int> ans;
        vector<pair<vector<string>,int>> f;
        for (int i = 0; i < x.size(); i++) {
            f.push_back({x[i], i});
        }
        sort(f.begin(), f.end(), [&](const pair<vector<string>,int>& a, const pair<vector<string>,int>& b) {
            return a.first.size() > b.first.size();
        });
        for (int i = 0; i < f.size(); i++) {
            bool g = 1;
            sort(f[i].first.begin(), f[i].first.end());
            for (int j = 0; j < i; j++) {
                int k = 0;
                for (int l = 0; k < f[i].first.size() && l < f[j].first.size(); l++) {
                    if (f[i].first[k] == f[j].first[l]) {
                        k++;
                    }
                }
                if (k == f[i].first.size()) {
                    g = 0;
                    break;
                }
            }
            if (g) {
                ans.push_back(f[i].second);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
