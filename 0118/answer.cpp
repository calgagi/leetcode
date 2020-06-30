class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(1, vector<int>(1, 1));
        if (numRows == 0) return vector<vector<int>>();
        for (int i = 1; i < numRows; i++) {
            r.push_back(vector<int>());
            r[i].push_back(1);
            for (int j = 1; j < r[i-1].size(); j++) {
                r[i].push_back(r[i-1][j-1] + r[i-1][j]);
            } 
            r[i].push_back(1);
        }
        return r;
    }
};
