class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Greedy: Take maximum area covered
        vector<pair<int,int>> r;
        for (int i = 0; i <= n; i++) {
            r.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
        }
        sort(r.begin(), r.end());
        int next_max = 0, i = 0, res = 0;
        while (i < (int) r.size()) {
            int next_next_max = next_max;
            while (i < (int) r.size() && r[i].first <= next_max) {
                next_next_max = max(r[i].second, next_next_max);
                i++;
            }
            if (next_next_max <= next_max) break;
            res++;
            next_max = next_next_max;
        }
        return (next_max < n ? -1 : res);
    }
};
