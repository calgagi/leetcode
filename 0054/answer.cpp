class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int i = 0, m = matrix.size(), n = matrix[0].size();
        while (res.size() != m*n) {
            for (int j = i; j < n-i && res.size() != m*n; j++)
                res.push_back(matrix[i][j]);
            for (int j = i+1; j < m-i && res.size() != m*n; j++)
                res.push_back(matrix[j][n-i-1]);
            for (int j = n-i-2; j >= i && res.size() != m*n; j--)
                res.push_back(matrix[m-i-1][j]);
            for (int j = m-i-2; j > i && res.size() != m*n; j--)
                res.push_back(matrix[j][i]);
            i++;
        }
        return res;
    }
};
