class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sorted(m + n-1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sorted[n-1+i-j].push_back(mat[i][j]);
            }
        }
        for (int i = 0; i < m+n-1; i++)
            sort(sorted[i].begin(), sorted[i].end(), greater<int>());
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sorted[n-1+i-j].back();
                sorted[n-1+i-j].pop_back();
            }
        }
        
        return mat;
    }
};
