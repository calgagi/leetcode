class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> r(quiet.size());
        for (int i = 0; i < quiet.size(); i++)
            r[i] = i;
        for (int i = 0; i < quiet.size(); i++) {
            stack<int> s;
            s.push({i});
            while (!s.empty()) {
                int x = s.top();
                s.pop();
                if (quiet[r[i]] > quiet[x]) {
                    r[i] = x;
                }
                if (x < i) {
                    if (quiet[r[i]] > quiet[r[x]]) {
                        r[i] = r[x];
                    }
                    continue;
                }
                for (int j = 0; j < richer.size(); j++) {
                    if (richer[j][1] == x) {
                        s.push(richer[j][0]);
                    }
                }
            }
        }
        return r;
    }
};
