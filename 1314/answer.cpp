class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix = mat, ret = mat;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] += (i>0?prefix[i-1][j]:0) + (j>0?prefix[i][j-1]:0) - (j>0&&i>0?prefix[i-1][j-1]:0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = prefix[min(m-1, i+K)][min(n-1, j+K)]
                            - (i-K-1>=0?prefix[i-K-1][min(n-1, j+K)]:0)
                            - (j-K-1>=0?prefix[min(m-1, i+K)][j-K-1]:0)
                            + (j-K-1>=0&&i-K-1>=0?prefix[i-K-1][j-K-1]:0);
            }
        }
        return ret;
    }
};
