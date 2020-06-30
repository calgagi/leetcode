class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -2);
        map<int,int> full;
        set<int> dry_day;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (full.count(rains[i])) {
                    int idx = full[rains[i]];
                    auto day = dry_day.upper_bound(idx);
                    if (day == dry_day.end()) {
                        return vector<int>();
                    }
                    ans[*day] = rains[i];
                    dry_day.erase(day);
                }
                full[rains[i]] = i;
                ans[i] = -1;
            } else {
                dry_day.insert(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -2) {
                ans[i] = 1;
            }
        }
        return ans;
    }
};
