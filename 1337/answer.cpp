class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> rows;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += mat[i][j];
            }
            rows.emplace_back(s, i);
        }
        sort(rows.begin(), rows.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(rows[i].second);
        return res;
    }
};
