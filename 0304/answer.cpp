class NumMatrix {
public:
    vector<vector<int>> prefix;
    
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = matrix[i][j];
                prefix[i][j] += i > 0 ? prefix[i-1][j] : 0;
                prefix[i][j] += j > 0 ? prefix[i][j-1] : 0;
                prefix[i][j] -= j > 0 && i > 0 ? prefix[i-1][j-1] : 0;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefix[row2][col2];
        res -= row1 > 0 ? prefix[row1-1][col2] : 0;
        res -= col1 > 0 ? prefix[row2][col1-1] : 0;
        res += col1 > 0 && row1 > 0 ? prefix[row1-1][col1-1] : 0;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
