class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row, col;
        for (int i = 0; i < m; i++) {
            int x = INT_MAX, idx = -1;
            for (int j = 0; j < n; j++) {
                if (x > matrix[i][j]) {
                    x = matrix[i][j];
                    idx = j;
                }
            }
            int y = INT_MIN;
            for (int k = 0; k < m; k++) {
                y = max(y, matrix[k][idx]);
            }
            if (y == x) {
                res.push_back(x);
            }
        }
        return res;
    }
};
